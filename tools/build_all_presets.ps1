# PowerShell script to build all CommonLibF4 runtime presets
# Default: parallel build with up to 5 jobs. Use -Sequential to build sequentially.

param(
    [switch]$Sequential,
    [int]$MaxJobs = 5
)

$presets = @('all', 'flat', 'ng', 'f4', 'vr')
$startTime = Get-Date

if (-not $Sequential) {
    Write-Host "Building presets in parallel (max $MaxJobs concurrent jobs)..." -ForegroundColor Cyan
    Write-Host "Total presets to build: $($presets.Count)" -ForegroundColor Cyan
    Write-Host ""
    
    $jobs = @()
    $jobStartTimes = @{}
    
    foreach ($preset in $presets) {
        Write-Host "Starting build for preset: $preset" -ForegroundColor Yellow
        $jobStartTimes[$preset] = Get-Date
        
        $job = Start-Job -ScriptBlock {
            param($preset)
            
            Set-Location $using:PWD
            
            # Configure the preset
            xmake config --runtime_preset=$preset
            if ($LASTEXITCODE -ne 0) {
                return @{
                    Preset = $preset
                    Success = $false
                    ExitCode = $LASTEXITCODE
                    Error = "Configuration failed"
                }
            }
            
            # Build the preset
            xmake build
            return @{
                Preset = $preset
                Success = $LASTEXITCODE -eq 0
                ExitCode = $LASTEXITCODE
            }
        } -ArgumentList $preset
        
        $jobs += @{
            Job = $job
            Preset = $preset
        }
    }
    
    $results = @()
    
    Write-Host "Waiting for all builds to complete..." -ForegroundColor Cyan
    Write-Host ""
    
    # Wait for all jobs to complete
    Wait-Job ($jobs | ForEach-Object { $_.Job }) | Out-Null
    
    # Collect results from all jobs
    foreach ($jobInfo in $jobs) {
        $result = Receive-Job -Job $jobInfo.Job
        $endTime = Get-Date
        $duration = $endTime - $jobStartTimes[$jobInfo.Preset]
        
        $status = if ($result.Success) { "SUCCESS" } else { "FAILED" }
        $color = if ($result.Success) { "Green" } else { "Red" }
        
        Write-Host "[$status] $($jobInfo.Preset) completed in $($duration.ToString('mm\:ss\.fff'))" -ForegroundColor $color
        
        $results += @{
            Preset = $jobInfo.Preset
            Success = $result.Success
            ExitCode = $result.ExitCode
            Duration = $duration
        }
        
        Remove-Job -Job $jobInfo.Job -Force
    }
    
    Write-Host ""
    Write-Host "=== Parallel Build Summary ===" -ForegroundColor Cyan
    $totalDuration = (Get-Date) - $startTime
    Write-Host "Total elapsed time: $($totalDuration.ToString('mm\:ss\.fff'))" -ForegroundColor Cyan
    
    $successCount = ($results | Where-Object { $_.Success }).Count
    $failCount = $results.Count - $successCount
    
    Write-Host "Successful builds: $successCount/$($results.Count)" -ForegroundColor $(if ($failCount -eq 0) { "Green" } else { "Yellow" })
    
    if ($failCount -gt 0) {
        Write-Host "Failed builds: $failCount" -ForegroundColor Red
        foreach ($result in $results | Where-Object { -not $_.Success }) {
            Write-Host "  - $($result.Preset) (Exit code: $($result.ExitCode))" -ForegroundColor Red
        }
    }
    
    # Individual job timing details
    Write-Host ""
    Write-Host "=== Individual Job Times ===" -ForegroundColor Cyan
    foreach ($result in $results | Sort-Object Duration -Descending) {
        $status = if ($result.Success) { "PASS" } else { "FAIL" }
        $color = if ($result.Success) { "Green" } else { "Red" }
        Write-Host "[$status] $($result.Preset): $($result.Duration.ToString('mm\:ss\.fff'))" -ForegroundColor $color
    }
    
    exit $(if ($failCount -eq 0) { 0 } else { 1 })
    
} else {
    Write-Host "Building presets sequentially..." -ForegroundColor Cyan
    Write-Host "Total presets to build: $($presets.Count)" -ForegroundColor Cyan
    Write-Host ""
    
    $results = @()
    $successCount = 0
    
    foreach ($preset in $presets) {
        Write-Host "Building preset: $preset" -ForegroundColor Yellow
        $presetStartTime = Get-Date
        
        # Configure the preset
        xmake config --runtime_preset=$preset
        if ($LASTEXITCODE -ne 0) {
            Write-Host "[FAILED] Configuration failed for preset: $preset" -ForegroundColor Red
            $results += @{
                Preset = $preset
                Success = $false
                ExitCode = $LASTEXITCODE
                Duration = (Get-Date) - $presetStartTime
            }
            continue
        }
        
        # Build the preset
        xmake build
        $success = $LASTEXITCODE -eq 0
        $presetEndTime = Get-Date
        $duration = $presetEndTime - $presetStartTime
        
        $status = if ($success) { "SUCCESS" } else { "FAILED" }
        $color = if ($success) { "Green" } else { "Red" }
        
        Write-Host "[$status] $preset completed in $($duration.ToString('mm\:ss\.fff'))" -ForegroundColor $color
        
        if ($success) {
            $successCount++
        }
        
        $results += @{
            Preset = $preset
            Success = $success
            ExitCode = $LASTEXITCODE
            Duration = $duration
        }
        
        Write-Host ""
    }
    
    # Summary
    Write-Host "=== Sequential Build Summary ===" -ForegroundColor Cyan
    $totalDuration = (Get-Date) - $startTime
    Write-Host "Total elapsed time: $($totalDuration.ToString('mm\:ss\.fff'))" -ForegroundColor Cyan
    
    $failCount = $results.Count - $successCount
    Write-Host "Successful builds: $successCount/$($results.Count)" -ForegroundColor $(if ($failCount -eq 0) { "Green" } else { "Yellow" })
    
    if ($failCount -gt 0) {
        Write-Host "Failed builds: $failCount" -ForegroundColor Red
        foreach ($result in $results | Where-Object { -not $_.Success }) {
            Write-Host "  - $($result.Preset) (Exit code: $($result.ExitCode))" -ForegroundColor Red
        }
    }
    
    # Individual job timing details
    Write-Host ""
    Write-Host "=== Individual Job Times ===" -ForegroundColor Cyan
    foreach ($result in $results) {
        $status = if ($result.Success) { "PASS" } else { "FAIL" }
        $color = if ($result.Success) { "Green" } else { "Red" }
        Write-Host "[$status] $($result.Preset): $($result.Duration.ToString('mm\:ss\.fff'))" -ForegroundColor $color
    }
    
    exit $(if ($failCount -eq 0) { 0 } else { 1 })
} 