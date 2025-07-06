# PowerShell script to build all CommonLibF4 runtime presets

$presets = @('all', 'flat', 'ng', 'f4', 'vr')

foreach ($preset in $presets) {
    Write-Host "\n=== Building preset: $preset ===" -ForegroundColor Cyan
    xmake f --runtime_preset=$preset
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Failed to configure preset: $preset" -ForegroundColor Red
        exit 1
    }
    xmake build -v
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Build failed for preset: $preset" -ForegroundColor Red
        exit 1
    }
    Write-Host "Build succeeded for preset: $preset" -ForegroundColor Green
}

Write-Host "\nAll runtime presets built successfully!" -ForegroundColor Green 