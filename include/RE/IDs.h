#pragma once

namespace RE::ID
{
	namespace ActiveEffect
	{
		inline constexpr REL::RelocationID CheckDisplacementSpellOnTarget{ 1415178, 0 };
	}

	namespace Actor
	{
		inline constexpr REL::RelocationID AddPerk{ 187096, 2230121 }; 
		inline constexpr REL::RelocationID CanUseIdle{ 1223707, 2229592 }; 
		inline constexpr REL::RelocationID ClearAttackStates{ 1525555, 2229773 }; 
		inline constexpr REL::RelocationID EndInterruptPackage{ 575188, 2229892 }; 
		inline constexpr REL::RelocationID ExitCover{ 813697, 2231166 };
		inline constexpr REL::RelocationID GetAimVector{ 812909, 2230378 };
		inline constexpr REL::RelocationID GetClosestBone{ 812582, 2230051 };
		inline constexpr REL::RelocationID GetCollisionFilter{ 860480, 2277949 };
		inline constexpr REL::RelocationID GetCombatStyle{ 1270929, 2231053 }; 
		inline constexpr REL::RelocationID SetCurrentAmmoCount{ 812483, 2229952 };
		inline constexpr REL::RelocationID GetCurrentCollisionGroup{ 410500, 0 };
		inline constexpr REL::RelocationID GetCurrentFireLocation{ 0, 2231167 };
		inline constexpr REL::RelocationID GetDesiredSpeed{ 106892, 2230410 }; 
		inline constexpr REL::RelocationID GetHostileToActor{ 1148686, 2229968 }; 
		inline constexpr REL::RelocationID GetMountHandle{ 313362, 2231230 }; 
		inline constexpr REL::RelocationID GetLevel{ 661617, 2229734 }; 
		inline constexpr REL::RelocationID GetPerkRank{ 1368313, 2230125 }; 
		inline constexpr REL::RelocationID GetSex{ 812205, 2229674 };
		inline constexpr REL::RelocationID HandleDefaultAnimationSwitch{ 1163130, 2229780 }; 
		inline constexpr REL::RelocationID HandleItemEquip{ 164912, 2229781 }; 
		inline constexpr REL::RelocationID InitiateDoNothingPackage{ 89993, 2229807 }; 
		inline constexpr REL::RelocationID IsCrippled{ 1238666, 0 };
		inline constexpr REL::RelocationID IsFollowing{ 629579, 2230013 }; 
		inline constexpr REL::RelocationID IsJumping{ 1041558, 2229640 }; 
		inline constexpr REL::RelocationID IsPathValid{ 1522194, 2230279 }; 
		inline constexpr REL::RelocationID IsPathing{ 989661, 2234312 }; 
		inline constexpr REL::RelocationID IsPathingComplete{ 812805, 2230274 };
		inline constexpr REL::RelocationID IsQuadruped{ 812145, 2229614 };
		inline constexpr REL::RelocationID IsSneaking{ 1173627, 2207655 }; 
		inline constexpr REL::RelocationID Move{ 812465, 2229934 };
		inline constexpr REL::RelocationID PerformAction{ 813708, 2231177 };
		inline constexpr REL::RelocationID RemovePerk{ 812653, 2230122 };
		inline constexpr REL::RelocationID Reset3D{ 812444, 2229913 };
		inline constexpr REL::RelocationID RewardExperience{ 262786, 2230428 }; 
		inline constexpr REL::RelocationID SetGunState{ 977675, 2231175 }; 
		inline constexpr REL::RelocationID SetHeading{ 353571, 2229625 }; 
		inline constexpr REL::RelocationID TrespassAlarm{ 1109888, 2229834 }; 
		inline constexpr REL::RelocationID UpdateVoiceTimer{ 812709, 2230178 };
		inline constexpr REL::RelocationID GetBodyPartData{ 0, 2229571 };
		inline constexpr REL::RelocationID GetEquippedItem{ 0, 2231089 };
		inline constexpr REL::RelocationID GetCrimeTrackingFaction{ 0, 2229787 };
		inline constexpr REL::RelocationID ForceDetect{ 0, 2230194 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::RelocationID Singleton{ 1174340, 2690994 };
		inline constexpr REL::RelocationID EquipObject{ 988029, 2231392 }; 
		inline constexpr REL::RelocationID UnequipObject{ 1292493, 2231395 };
		inline constexpr REL::RelocationID UnequipItem{ 0, 2231399 };
	}

	namespace ActorUtils
	{
		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::RelocationID _operator{ 0, 2227206 };
			inline constexpr REL::RelocationID ctor{ 0, 2227205 };
		}
	}

	namespace ActorValue
	{
		inline constexpr REL::RelocationID Singleton{ 405390, 2189587 }; 
	}

	namespace AIProcess
	{
		inline constexpr REL::RelocationID GetCurrentAmmo{ 1154936, 2232300 }; 
		inline constexpr REL::RelocationID GetCommandType{ 678523, 2231825 }; 
		inline constexpr REL::RelocationID GetOccupiedFurniture{ 1162965, 2232401 }; 
		inline constexpr REL::RelocationID IsWeaponSubgraphFinishedLoading{ 320183, 2231757 }; 
		inline constexpr REL::RelocationID KnockExplosion{ 0, 2232384 };
		inline constexpr REL::RelocationID ProcessGreet{ 1174935, 2231808 }; 
		inline constexpr REL::RelocationID RequestLoadAnimationsForWeaponChange{ 0, 2231758 };
		inline constexpr REL::RelocationID SetActorsDetectionEvent{ 1376336, 2231738 }; 
		inline constexpr REL::RelocationID SetCurrentAmmo{ 795983, 2232302 }; 
		inline constexpr REL::RelocationID SetCommandType{ 0, 2231826 };
		inline constexpr REL::RelocationID SetEquippedItem{ 1200276, 0 };
		inline constexpr REL::RelocationID SetupSpecialIdle{ 0, 2231704 };
		inline constexpr REL::RelocationID SetWeaponBonesCulled{ 397172, 2232535 }; 
		inline constexpr REL::RelocationID StopCurrentIdle{ 434460, 2231705 }; 
	}

	namespace AnimationSystemUtils
	{
		inline constexpr REL::RelocationID WillEventChangeState{ 35074, 0 };
	}

	namespace ApplyChangesFunctor
	{
		inline constexpr REL::RelocationID WriteDataImpl{ 1291190, 2223194 }; 
	}

	namespace ApplyColorUpdateEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2707340 };
	}

	namespace BarterMenu
	{
		inline constexpr REL::RelocationID ClearTradingData{ 0, 2222700 };
		inline constexpr REL::RelocationID CompleteTrade{ 0, 2222701 };
		inline constexpr REL::RelocationID GetCapsOwedByPlayer{ 0, 2222714 };
	}

	namespace BGSAnimationSystemUtils
	{
		inline constexpr REL::RelocationID GetActiveSyncInfo{ 1349978, 0 };
		inline constexpr REL::RelocationID InitializeActorInstant{ 672857, 0 };
		inline constexpr REL::RelocationID IsActiveGraphInTransition{ 839650, 0 };
	}

	namespace BGSAttachParentArray
	{
		inline constexpr REL::RelocationID SetParentGroupNumber{ 1412266, 0 };
	}

	namespace BGSCraftItemEvent
	{
		inline constexpr REL::RelocationID EventIndex{ 1382765, 2663409 }; 
	}

	namespace BGSCreatedObjectManager
	{
		inline constexpr REL::RelocationID Singleton{ 1000678, 0 };
		inline constexpr REL::RelocationID DecrementRef{ 230928, 0 };
		inline constexpr REL::RelocationID IncrementRef{ 1042515, 0 };
	}

	namespace BGSDefaultObject
	{
		inline constexpr REL::RelocationID Singleton{ 561749, 2690473 }; 
		inline constexpr REL::RelocationID ctor{ 1144014, 2197003 }; 
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::RelocationID Singleton{ 484974, 0 };
	}

	namespace BGSDynamicPersistenceManager
	{
		inline constexpr REL::RelocationID Singleton{ 109630, 0 };
		inline constexpr REL::RelocationID PromoteReference{ 1300345, 0 };
		inline constexpr REL::RelocationID DemoteReference{ 222813, 0 };
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::RelocationID HandleEntryPoint{ 714336, 2206243 }; 
	}

	namespace BGSHackTerminal
	{
		inline constexpr REL::RelocationID EventIndex{ 0, 2663434 };
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::RelocationID Singleton{ 501899, 2689299 }; 
		inline constexpr REL::RelocationID RequestInventoryItem{ 1200959, 2194009 }; 
		inline constexpr REL::RelocationID ForceMergeStacks{ 0, 2194032 };
	}

	namespace BGSInventoryItem
	{
		inline constexpr REL::RelocationID FindAndWriteStackData{ 0, 2194123 };
		inline constexpr REL::RelocationID GetDisplayFullName1{ 277641, 2194079 }; 
		inline constexpr REL::RelocationID GetDisplayFullName2{ 0, 2194080 };
		inline constexpr REL::RelocationID GetInstanceData{ 491493, 2194072 }; 
		inline constexpr REL::RelocationID GetInventoryValue{ 430292, 2194099 }; 
		inline constexpr REL::RelocationID GetExtraDataAt{ 0, 2194092 };
		inline constexpr REL::RelocationID MergeStacks{ 0, 2194109 }; 
	}

	namespace BGSInventoryList
	{
		inline constexpr REL::RelocationID FindAndWriteStackDataForItem{ 0, 2194179 };
		inline constexpr REL::RelocationID BuildFromContainer{ 551792, 2194158 }; 
		inline constexpr REL::RelocationID ctor{ 0, 2194153 };
	}

	namespace BGSKeyword
	{
		inline constexpr REL::RelocationID TypedKeywords{ 0, 2692038 };
	}

	namespace BGSKeywordForm
	{
		inline constexpr REL::RelocationID AddKeyword{ 762999, 2192766 }; 
		inline constexpr REL::RelocationID RemoveKeyword{ 921694, 0 };
	}

	namespace BGSListForm
	{
		inline constexpr REL::RelocationID AddScriptAddedForm{ 0, 2203262 };
		inline constexpr REL::RelocationID ContainsItem{ 688500, 0 };
	}

	namespace BGSLocalizedStringDL
	{
		inline constexpr REL::RelocationID GetDescription{ 523613, 0 };
		inline constexpr REL::RelocationID GetText{ 472297, 0 };
	}

	namespace BGSMessage
	{
		inline constexpr REL::RelocationID AddButton{ 746523, 0 }; 
		inline constexpr REL::RelocationID GetConvertedDescription{ 8331, 0 };
	}

	namespace BGSMod
	{
		namespace Attachment
		{
			namespace Mod
			{
		inline constexpr REL::RelocationID FindModsForLooseMod{ 410363, 0 };
		inline constexpr REL::RelocationID GetData{ 33658, 0 };
				inline constexpr REL::RelocationID GetLooseMod{ 0, 2197514 };
		inline constexpr REL::RelocationID SetLooseMod{ 123132, 0 };
			}

		inline constexpr REL::RelocationID GetAllLooseMods{ 1108112, 0 };
		}

		namespace Template
		{
			namespace Items
			{
		inline constexpr REL::RelocationID CreateInstanceDataForObjectAndExtra{ 147297, 0 };
			}
		}
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::RelocationID ctor{ 0, 2197563 };
	}

	namespace BGSObjectInstanceExtra
	{
		inline constexpr REL::RelocationID AttachModToReference{ 3303, 2189033 }; 
		inline constexpr REL::RelocationID HasMod{ 963890, 2189026 }; 
		inline constexpr REL::RelocationID AddMod{ 1191757, 2189025 }; 
		inline constexpr REL::RelocationID RemoveInvalidMods{ 1548060, 2189028 }; 
		inline constexpr REL::RelocationID RemoveMod{ 1136607, 2189027 }; 
		inline constexpr REL::RelocationID GetNumMods{ 0, 2189019 };
		inline constexpr REL::RelocationID ctor{ 0, 2189015 };
	}

	namespace BGSOpenCloseForm
	{
		inline constexpr REL::RelocationID AutoCloseRef{ 0, 2192797 };
		inline constexpr REL::RelocationID GetOpenState{ 0, 2192799 };
		inline constexpr REL::RelocationID HasOnlyOpenCloseAnims{ 0, 2192796 };
		inline constexpr REL::RelocationID IsAnimating{ 0, 2192801 };
		inline constexpr REL::RelocationID IsOpenCloseEvent{ 0, 2192795 };
		inline constexpr REL::RelocationID IsOpenCloseForm{ 0, 2192790 };
		inline constexpr REL::RelocationID SetOpenState{ 0, 2192798 };
	}

	namespace BGSPerkRankArray
	{
		inline constexpr REL::RelocationID AllocatePerkRankArray{ 888419, 0 };
		inline constexpr REL::RelocationID ClearPerks{ 1247917, 0 };
	}

	namespace BGSPickLockEvent
	{
		inline constexpr REL::RelocationID EventIndex{ 701969, 0 };
		inline constexpr REL::RelocationID ctor{ 193329, 0 };
	}

	namespace BGSProjectile
	{
		inline constexpr REL::RelocationID CollidesWithSmallTransparentLayer{ 1115694, 2197620 }; 
	}

	namespace BGSQuestInstanceText
	{
		inline constexpr REL::RelocationID ParseString{ 141681, 2206630 }; 
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::RelocationID Singleton{ 1247320, 2697802 }; 
		inline constexpr REL::RelocationID QueueSaveLoadTask{ 1487308, 2228080 }; 
	}

	namespace BGSScene
	{
		inline constexpr REL::RelocationID ResetAllSceneActions{ 0, 2206864 };
		inline constexpr REL::RelocationID SetSceneActive{ 0, 2206845 };
	}

	namespace BGSSceneActionNPCResponseDialogue
	{
		inline constexpr REL::RelocationID GetCurrentTopicInfo{ 0, 2196825 };
	}

	namespace BGSSceneActionPlayerDialogue
	{
		inline constexpr REL::RelocationID GetCurrentTopicInfo{ 0, 2196825 };
	}

	namespace BGSStoryEventManager
	{
		inline constexpr REL::RelocationID Singleton{ 1160067, 2693504 }; 
		inline constexpr REL::RelocationID AddEvent{ 312533, 2214088 }; 
	}

	namespace BGSSynchronizedAnimationManager
	{
		inline constexpr REL::RelocationID Singleton{ 1346879, 2690996 }; 
		inline constexpr REL::RelocationID IsReferenceInSynchronizedScene{ 915329, 2214437 }; 
	}

	namespace BGSTerminal
	{
		inline constexpr REL::RelocationID GetHackDifficultyLockLevel{ 537273, 2197777 }; 
		inline constexpr REL::RelocationID IsTerminalRefInUse{ 1093565, 2197779 }; 
		inline constexpr REL::RelocationID Show{ 1069012, 2197776 }; 
	}

	namespace bhkNPCollisionObject
	{
		inline constexpr REL::RelocationID CopyMembers{ 0, 2277907 };
		inline constexpr REL::RelocationID GetBody{ 0, 2277926 };
		inline constexpr REL::RelocationID GetBodyId{ 0, 2277928 };
		inline constexpr REL::RelocationID GetShape{ 0, 2277929 };
		inline constexpr REL::RelocationID GetTransform{ 1508189, 0 };
		inline constexpr REL::RelocationID SetMotionType{ 0, 2277913 };
		inline constexpr REL::RelocationID SetTransform{ 178085, 0 };
		inline constexpr REL::RelocationID Getbhk{ 0, 2277919 };
	}

	namespace bhkPhysicsSystem
	{
		inline constexpr REL::RelocationID AddToWorld{ 0, 2278019 };
		inline constexpr REL::RelocationID CopyMembers{ 0, 2278007 };
	}

	namespace bhkPickData
	{
		inline constexpr REL::RelocationID ctor{ 526783, 0 };
		inline constexpr REL::RelocationID SetStartEnd{ 747470, 0 };
		inline constexpr REL::RelocationID Reset{ 438299, 0 };
		inline constexpr REL::RelocationID HasHit{ 1181584, 0 };
		inline constexpr REL::RelocationID GetHitFraction{ 476687, 0 };
		inline constexpr REL::RelocationID GetAllCollectorRayHitSize{ 1288513, 0 };
		inline constexpr REL::RelocationID GetAllCollectorRayHitAt{ 583997, 0 };
		inline constexpr REL::RelocationID SortAllCollectorHits{ 1274842, 0 };
		inline constexpr REL::RelocationID GetNiAVObject{ 863406, 0 };
		inline constexpr REL::RelocationID GetBody{ 1223055, 0 };
	}

	namespace bhkUtilFunctions
	{
		inline constexpr REL::RelocationID FindFirstCollisionObject{ 0, 2278093 };
	}

	namespace bhkWorld
	{
		inline constexpr REL::RelocationID AddPhysicsSystem{ 0, 2277752 };
		inline constexpr REL::RelocationID RemovePhysicsSystem{ 0, 2277753 };
		inline constexpr REL::RelocationID RemoveObjects{ 1514984, 2277721 }; 
	}

	namespace BIPOBJECT
	{
		inline constexpr REL::RelocationID dtor{ 765242, 0 };
	}

	namespace BSAudioManager
	{
		inline constexpr REL::RelocationID Singleton{ 1321158, 0 };
		inline constexpr REL::RelocationID GetSoundHandleByName{ 196484, 0 };
	}

	namespace BSAwardsSystemUtility
	{
		inline constexpr REL::RelocationID Singleton{ 1569384, 0 };
	}

	namespace BSGFxDisplayObject
	{
		inline constexpr REL::RelocationID RemoveChild{ 1229383, 2287327 }; 
	}

	namespace BSGFxObject
	{
		inline constexpr REL::RelocationID AcquireFlashObjectByMemberName{ 1172680, 2287014 }; 
		inline constexpr REL::RelocationID AcquireFlashObjectByPath{ 0, 2287015 };
	}

	namespace BSGFxShaderFXTarget
	{
		inline constexpr REL::RelocationID ProcessEvent{ 848563, 0 };
		inline constexpr REL::RelocationID AppendShaderFXInfos{ 544646, 2287021 }; 
		inline constexpr REL::RelocationID CreateAndSetFiltersToColor1{ 1487925, 2287028 }; 
		inline constexpr REL::RelocationID CreateAndSetFiltersToColor2{ 783104, 0 };
		inline constexpr REL::RelocationID CreateAndSetFiltersToHUD{ 876001, 2287027 }; 
		inline constexpr REL::RelocationID EnableShadedBackground{ 278402, 2287022 }; 
	}

	namespace BSGraphics
	{
		namespace Renderer
		{
		inline constexpr REL::RelocationID IncRef{ 1337764, 0 };
		inline constexpr REL::RelocationID DecRef{ 194808, 0 };
			inline constexpr REL::RelocationID Begin{ 0, 2276833 };
			inline constexpr REL::RelocationID End{ 0, 2276834 };
			inline constexpr REL::RelocationID Lock{ 0, 2276828 };
			inline constexpr REL::RelocationID Unlock{ 0, 2276829 };
		}

		namespace RenderTargetManager
		{
			inline constexpr REL::RelocationID Singleton{ 0, 2666735 };
		inline constexpr REL::RelocationID SetEnableDynamicResolution{ 116947, 0 };
		}

		namespace State
		{
			inline constexpr REL::RelocationID Singleton{ 0, 2704621 };
		}

		namespace Utility
		{
			inline constexpr REL::RelocationID ConvertHALFToNiPoint3Stream{ 463129, 2277113 }; 
			inline constexpr REL::RelocationID ConvertNiPoint3ToHALFStream{ 0, 2277114 }; 
			inline constexpr REL::RelocationID PackVertexData{ 156126, 2277106 }; 
			inline constexpr REL::RelocationID UnpackVertexData{ 990748, 2277129 }; 
		}

		inline constexpr REL::RelocationID GetRendererData{ 0, 2704429 };
		inline constexpr REL::RelocationID GetCurrentRendererWindow{ 0, 2704431 };
	}

	namespace BSInputDeviceManager
	{
		inline constexpr REL::RelocationID Singleton{ 1284221, 0 };
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::RelocationID DecRef{ 0, 2268272 };
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689007 };
		inline constexpr REL::RelocationID AllocateNewLayer{ 0, 2268244 };
		inline constexpr REL::RelocationID EnableUserEvent{ 0, 2268263 };
		inline constexpr REL::RelocationID EnableOtherEvent{ 0, 2268265 };
	}

	namespace BSModelDB
	{
		inline constexpr REL::RelocationID Demand1{ 0, 2275153 };
		inline constexpr REL::RelocationID Demand2{ 0, 2275154 };
	}

	namespace BSPointerHandle
	{
		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::RelocationID CreateHandle{ 224532, 2188375 }; 
			inline constexpr REL::RelocationID GetHandle{ 901626, 2188676 }; 
			inline constexpr REL::RelocationID GetSmartPointer{ 967277, 2188681 }; 
		}
	}

	namespace BSRandom
	{
		inline constexpr REL::RelocationID UnsignedInt{ 694400, 2267950 }; 
		inline constexpr REL::RelocationID Float{ 0, 2267953 };
		inline constexpr REL::RelocationID Float0To1{ 0, 2267954 };
	}

	namespace BSResource_Archive2_AsyncReaderStream
	{
		inline constexpr REL::RelocationID DoOpen{ 1401160, 0 };
		inline constexpr REL::RelocationID DoClose{ 883012, 0 };
		inline constexpr REL::RelocationID DoClone{ 803750, 0 };
		inline constexpr REL::RelocationID DoStartRead{ 1215072, 0 };
		inline constexpr REL::RelocationID DoStartPacketAlignedBufferedRead{ 603387, 0 };
		inline constexpr REL::RelocationID DoWait{ 244066, 2269399 }; 
	}

	namespace BSResource_Archive2_ReaderStream
	{
		inline constexpr REL::RelocationID DoOpen{ 762048, 0 };
		inline constexpr REL::RelocationID DoClose{ 109149, 0 };
		inline constexpr REL::RelocationID DoGetKey{ 772817, 0 };
		inline constexpr REL::RelocationID DoClone{ 855081, 0 };
		inline constexpr REL::RelocationID DoRead{ 1359347, 0 };
		inline constexpr REL::RelocationID DoSeek{ 1000164, 0 };
		inline constexpr REL::RelocationID DoPrefetchAll{ 1518821, 0 };
		inline constexpr REL::RelocationID DoCreateAsync{ 893405, 0 };
	}

	namespace BSResource_EntryDBBaseUtil
	{
		inline constexpr REL::RelocationID ReleaseEntryAction{ 0, 2269463 };
	}

	namespace BSResource_GlobalLocations
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2703394 };
	}

	namespace BSResource_GlobalPaths
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2703393 };
	}

	namespace BSResource
	{
		inline constexpr REL::RelocationID RegisterLocation{ 918408, 0 };
		inline constexpr REL::RelocationID GetOrCreateStream{ 1143155, 0 };
	}

	namespace BSResourceNiBinaryStream
	{
		inline constexpr REL::RelocationID Seek{ 0, 2269834 };
		inline constexpr REL::RelocationID DoRead{ 0, 2269839 };
		inline constexpr REL::RelocationID DoWrite{ 0, 2269840 };
		inline constexpr REL::RelocationID GetBufferInfo{ 0, 2269836 };
		inline constexpr REL::RelocationID Ctor{ 0, 2269830 };
		inline constexpr REL::RelocationID Dtor{ 0, 2269832 };
		inline constexpr REL::RelocationID BinaryStreamWithRescan{ 746523, 0 }; 
	}

	namespace BSScaleformManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689600 };
		inline constexpr REL::RelocationID LoadMovie{ 0, 2287422 };
		inline constexpr REL::RelocationID GetMovieFilename{ 1191277, 0 };
		inline constexpr REL::RelocationID InitMovieViewport{ 0, 2287430 };
		inline constexpr REL::RelocationID FileUncacheOnMenuOpen{ 0, 2667999 };
	}

	namespace BSScaleformRenderer
	{
		inline constexpr REL::RelocationID Initialize{ 0, 2284938 };
	}

	namespace BSScaleformTranslator
	{
		inline constexpr REL::RelocationID AddTranslations{ 0, 2295298 };
	}

	namespace BSScript_Array
	{
		inline constexpr REL::RelocationID ctor{ 870924, 0 };
	}

	namespace BSScript_ArrayWrapper
	{
		inline constexpr REL::RelocationID ReplaceArray{ 445184, 0 };
	}

	namespace BSScript_Internal_NativeFunctionBase
	{
		inline constexpr REL::RelocationID Call{ 571037, 2314780 }; 
	}

	namespace BSScript_Internal_Stack
	{
		inline constexpr REL::RelocationID GetPageForFrame{ 1429302, 0 };
		inline constexpr REL::RelocationID GetStackFrameVariable{ 897539, 2314681 }; 
	}

	namespace BSScript_Object
	{
		inline constexpr REL::RelocationID DecRef{ 541793, 0 };
		inline constexpr REL::RelocationID GetHandle{ 1452752, 2314431 }; 
		inline constexpr REL::RelocationID IncRef{ 461710, 2314436 }; 
	}

	namespace BSScript_ObjectTypeInfo
	{
		inline constexpr REL::RelocationID dtor{ 1047917, 0 };
	}

	namespace BSScript_ObjectBindPolicy
	{
		inline constexpr REL::RelocationID BindObject{ 709728, 0 };
		inline constexpr REL::RelocationID UnbindObject{ 522763, 0 };
	}

	namespace BSScriptUtil
	{
		inline constexpr REL::RelocationID BaseObjectName{ 648543, 0 };
	}

	namespace BSShaderProperty
	{
		inline constexpr REL::RelocationID SetMaterial{ 0, 2316285 };
	}

	namespace BSShaderTextureSet
	{
		inline constexpr REL::RelocationID CreateObject{ 0, 2316324 }; 
	}

	namespace BSSoundHandle
	{
		inline constexpr REL::RelocationID FadeInPlay{ 0, 2267075 };
		inline constexpr REL::RelocationID FadeOutAndRelease{ 0, 2267076 };
	}

	namespace BSSpinLock
	{
		namespace BSReadWriteLock
		{
			inline constexpr REL::RelocationID lock_read{ 1573164, 2267897 }; 
			inline constexpr REL::RelocationID lock_write{ 336186, 2267898 }; 
			inline constexpr REL::RelocationID try_lock_read{ 1372435, 2267901 }; 
			inline constexpr REL::RelocationID try_lock_write{ 267930, 2267902 }; 
		}

		inline constexpr REL::RelocationID lock{ 1425657, 2192245 }; 
		inline constexpr REL::RelocationID try_lock{ 267930, 2267902 }; 
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::RelocationID Release{ 1204430, 2268720 }; 
		}

		inline constexpr REL::RelocationID GetEntry_char{ 507142, 2268729 }; 
		inline constexpr REL::RelocationID GetEntry_wchar{ 345043, 2268730 }; 
	}

	namespace BSStringT
	{
		inline constexpr REL::RelocationID Set{ 0, 2189084 }; 
	}

	namespace BSSystemFileStreamer
	{
		inline constexpr REL::RelocationID UncacheAll{ 0, 2268797 };
	}

	namespace BSTempEffectDebris
	{
		inline constexpr REL::RelocationID ctor{ 1075623, 2212059 }; 
	}

	namespace BSTEvent
	{
		namespace BSTGlobalEvent
		{
			inline constexpr REL::RelocationID Singleton{ 1424022, 2688814 }; 
		}
	}

	namespace BSThreadEvent
	{
		inline constexpr REL::RelocationID InitSDM{ 0, 2268180 };
	}

	namespace BSTimer
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2703179 };
		inline constexpr REL::RelocationID QGlobalTimeMultiplier{ 0, 2666307 };
		inline constexpr REL::RelocationID QGlobalTimeMultiplierTarget{ 0, 2666308 }; 
		inline constexpr REL::RelocationID SetGlobalTimeMultiplier{ 1419977, 2267970 }; 
	}

	namespace BSUIMessageData
	{
		inline constexpr REL::RelocationID SendUIBoolMessage{ 1388308, 0 };
		inline constexpr REL::RelocationID SendUIStringMessage{ 1270833, 0 };
		inline constexpr REL::RelocationID SendUIPtrMessage{ 1374542, 0 };
		inline constexpr REL::RelocationID SendUIStringUIntMessage{ 99795, 0 };
	}

	namespace BSUtilities
	{
		inline constexpr REL::RelocationID ConvertFloatToHalf{ 10414, 2212098 }; 
		inline constexpr REL::RelocationID ConvertHalfToFloat{ 1502141, 2195843 }; 
		inline constexpr REL::RelocationID GetObjectByName{ 0, 2274841 };
	}

	namespace Calendar
	{
		inline constexpr REL::RelocationID Singleton{ 1444952, 2689092 }; 
	}

	namespace CanDisplayNextHUDMessage
	{
		inline constexpr REL::RelocationID GetEventSource{ 344866, 0 };
	}

	namespace CellAttachDetachEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 862142, 0 };
	}

	namespace ColorUpdateEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1226590, 0 };
	}

	namespace CombatFormulas
	{
		inline constexpr REL::RelocationID GetWeaponDisplayAccuracy{ 0, 2209049 };
		inline constexpr REL::RelocationID GetWeaponDisplayDamage{ 1431014, 0 };
		inline constexpr REL::RelocationID GetWeaponDisplayRange{ 1324037, 0 };
		inline constexpr REL::RelocationID GetWeaponDisplayRateOfFire{ 1403591, 0 };
	}

	namespace CombatUtilities
	{
		inline constexpr REL::RelocationID CalculateProjectileLOS1{ 798616, 0 };
		inline constexpr REL::RelocationID CalculateProjectileLOS2{ 55339, 0 };
		inline constexpr REL::RelocationID CalculateProjectileTrajectory{ 1575156, 0 };
		inline constexpr REL::RelocationID WorldGravity{ 1378547, 0 };
	}

	namespace ComparisonQualifiers
	{
		inline constexpr REL::RelocationID ContainerQualifier{ 0, 2190674 };
		inline constexpr REL::RelocationID UIQualifier{ 0, 2190675 };
	}

	namespace Console
	{
		inline constexpr REL::RelocationID ExecuteCommand{ 1061864, 2248537 }; 
		inline constexpr REL::RelocationID GetCurrentPickIndex{ 1407033, 2701382 };
		inline constexpr REL::RelocationID GetPickRef{ 170742, 2701395 };
		inline constexpr REL::RelocationID GetPickRefs{ 875116, 2701391 };
		inline constexpr REL::RelocationID SetCurrentPickREFR{ 79066, 2248551 }; 
	}

	namespace ConsoleLog
	{
		inline constexpr REL::RelocationID Singleton{ 689441, 2690148 }; 
		inline constexpr REL::RelocationID AddString{ 764, 2248593 }; 
		inline constexpr REL::RelocationID Print{ 799546, 2248591 }; 
	}

	namespace ContainerMenu
	{
		inline constexpr REL::RelocationID TakeAllItems{ 0, 2248619 };
	}

	namespace ContainerMenuBase
	{
		namespace ItemSorter
		{
		inline constexpr REL::RelocationID IncrementSort{ 1307263, 0 };
		}
	}

	namespace ControlMap
	{
		inline constexpr REL::RelocationID Singleton{ 325206, 2692014 }; 
		inline constexpr REL::RelocationID PopInputContext{ 74587, 2268336 }; 
		inline constexpr REL::RelocationID PushInputContext{ 1404410, 2268335 }; 
		inline constexpr REL::RelocationID RemapButton{ 0, 2268330 };
		inline constexpr REL::RelocationID SaveRemappings{ 746523, 0 }; 
		inline constexpr REL::RelocationID SetTextEntryMode{ 0, 2268339 };
	}

	namespace CurrentRadiationSourceCount
	{
		inline constexpr REL::RelocationID GetEventSource{ 696410, 2696196 }; 
	}

	namespace DEFAULT_OBJECT_DATA
	{
		inline constexpr REL::RelocationID GetDefaultObjectData{ 838886, 0 };
	}

	namespace DialogueMenuUtils
	{
		inline constexpr REL::RelocationID OpenMenu{ 0, 2249658 };
		inline constexpr REL::RelocationID CloseMenu{ 0, 2249659 };
		inline constexpr REL::RelocationID ShowSpeechChallengeAnim{ 0, 2249665 };
	}

	namespace DoBeforeNewOrLoadCompletedEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 787908, 0 };
	}

	namespace EffectItem
	{
		inline constexpr REL::RelocationID GetDescription{ 0, 2189612 };
	}

	namespace EquippedWeaponData
	{
		inline constexpr REL::RelocationID SetupFireSounds{ 1468462, 2232275 }; 
	}

	namespace ExamineMenu
	{
		inline constexpr REL::RelocationID BuildWeaponScrappingArray{ 646841, 0 };
		inline constexpr REL::RelocationID GetSelectedIndex{ 0, 2223022 };
		inline constexpr REL::RelocationID ShowConfirmMenu{ 0, 2223081 };
		inline constexpr REL::RelocationID ConsumeSelectedItems{ 0, 2223052 };
	}

	namespace ExteriorCellSingleton
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689084 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::RelocationID CreateInstanceData{ 1280130, 2190185 }; 
		inline constexpr REL::RelocationID GetLegendaryMod{ 178075, 2190180 }; 
		inline constexpr REL::RelocationID SetBendableSplineInfo{ 894306, 2190623 }; 
		inline constexpr REL::RelocationID SetDisplayNameFromInstanceData{ 457340, 2190179 }; 
		inline constexpr REL::RelocationID SetOverrideName{ 222303, 2190167 }; 
		inline constexpr REL::RelocationID SetStartingWorldOrCell{ 603621, 2191213 }; 
		inline constexpr REL::RelocationID GetHealthPerc{ 196530, 2190226 }; 
		inline constexpr REL::RelocationID SetHealthPerc{ 1208294, 2190124 }; 
		inline constexpr REL::RelocationID ClearFavorite{ 254434, 2190191 }; 
		inline constexpr REL::RelocationID IsFavorite{ 786568, 2190189 }; 
		inline constexpr REL::RelocationID IsDamaged{ 0, 2190224 };
		inline constexpr REL::RelocationID CompareList{ 0, 2190098 };
		inline constexpr REL::RelocationID SetFavorite{ 0, 2190188 };
		inline constexpr REL::RelocationID GetPrimitive{ 0, 2190427 };
	}

	namespace ExtraTextDisplayData
	{
		inline constexpr REL::RelocationID GetDisplayName{ 0, 2191318 };
	}

	namespace FavoritesManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2694399 };
		inline constexpr REL::RelocationID IsComponentFavorite{ 0, 2248752 };
		inline constexpr REL::RelocationID UseQuickkeyItem{ 0, 2248744 };
	}

	namespace FlatScreenModel
	{
		inline constexpr REL::RelocationID Singleton{ 847741, 0 };
	}

	namespace GameMenuBase
	{
		inline constexpr REL::RelocationID SetIsTopButtonBar{ 0, 2223204 };
		inline constexpr REL::RelocationID OnMenuDisplayStateChanged{ 0, 2223205 };
		inline constexpr REL::RelocationID CacheShaderFXQuadsForRenderer_Impl{ 0, 2223200 };
		inline constexpr REL::RelocationID TransferCachedShaderFXQuadsForRenderer{ 65166, 0 };
		inline constexpr REL::RelocationID SetViewportRect{ 0, 2223202 };
		inline constexpr REL::RelocationID AppendShaderFXInfos{ 0, 2223203 };
		inline constexpr REL::RelocationID SetUpButtonBar{ 0, 2223197 };
	}

	namespace GamePlayFormulas
	{
		inline constexpr REL::RelocationID CanHackGateCheck{ 269668, 0 };
		inline constexpr REL::RelocationID CanPickLockGateCheck{ 1160841, 0 };
		inline constexpr REL::RelocationID GetExperienceReward{ 0, 2209076 };
		inline constexpr REL::RelocationID GetLockXPReward{ 0, 2209070 };
		inline constexpr REL::RelocationID CalculateItemHealthDamageBonus{ 0, 2209087 };
	}

	namespace GameScript
	{
		namespace HandlePolicy
		{
			inline constexpr REL::RelocationID DropSaveLoadRemapData{ 647657, 2249995 }; 
			inline constexpr REL::RelocationID GetInventoryObjFromHandle{ 66597, 2249989 }; 
			inline constexpr REL::RelocationID UpdatePersistence{ 11020, 2249991 }; 
		}

		namespace ObjectBindPolicy
		{
			inline constexpr REL::RelocationID EndSaveLoad{ 1558837, 2250482 }; 
		}

		namespace GameVM
		{
			inline constexpr REL::RelocationID Singleton{ 996227, 2689134 }; 
			inline constexpr REL::RelocationID QueuePostRenderCall{ 34412, 2251314 }; 
			inline constexpr REL::RelocationID RegisterForAllGameEvents{ 680454, 2251353 }; 
		inline constexpr REL::RelocationID SendEventToObjectAndRelated{ 367992, 0 };
		}

		inline constexpr REL::RelocationID LogFormError{ 1081933, 2251028 }; 
		inline constexpr REL::RelocationID BindCObject{ 81787, 0 };
	}

	namespace GameUIModel
	{
		inline constexpr REL::RelocationID Singleton{ 17419, 0 };
		inline constexpr REL::RelocationID UpdateDataModels{ 0, 2220905 };
	}

	namespace GridCellArray
	{
		inline constexpr REL::RelocationID Get{ 0, 2194566 };
	}

	namespace HolotapeMenu
	{
		inline constexpr REL::RelocationID ShowHolotapeInPipboy{ 0, 2224028 };
		inline constexpr REL::RelocationID ShowHolotapeInTerminal{ 0, 2224029 };
	}

	namespace HUDMenuUtils
	{
		inline constexpr REL::RelocationID GetGameplayHUDColor{ 0, 2248840 };
		inline constexpr REL::RelocationID GetGameplayHUDBackgroundColor{ 0, 2248845 };
		inline constexpr REL::RelocationID WorldPtToScreenPt3{ 0, 2222464 };
	}

	namespace HUDModeEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 683142, 0 };
	}

	namespace IAnimationGraphManagerHolder
	{
		inline constexpr REL::RelocationID SetGraphVariableBool{ 0, 2214543 };
		inline constexpr REL::RelocationID SetGraphVariableFloat{ 27400, 0 };
		inline constexpr REL::RelocationID SetGraphVariableInt{ 732926, 0 };
		inline constexpr REL::RelocationID RevertAnimationGraphManager{ 0, 2214541 };
	}

	namespace IFormFactory
	{
		inline constexpr REL::RelocationID Factories{ 228366, 2689177 }; 
	}

	namespace ImageSpaceEffectFullScreenBlur
	{
		inline constexpr REL::RelocationID Disable{ 372489, 2713225 }; 
	}

	namespace ImageSpaceEffectGetHit
	{
		inline constexpr REL::RelocationID Disable{ 1523708, 2713237 }; 
	}

	namespace ImageSpaceEffectHDR
	{
		inline constexpr REL::RelocationID UsePipboyScreenMask{ 0, 2678029 };
	}

	namespace ImageSpaceEffectPipboyScreen
	{
		inline constexpr REL::RelocationID PowerArmorPipboy{ 1065542, 0 };
	}

	namespace ImageSpaceEffectRadialBlur
	{
		inline constexpr REL::RelocationID Disable{ 372489, 2713225 }; 
	}

	namespace ImageSpaceEffectTemporalAA
	{
		inline constexpr REL::RelocationID MaskS{ 775377, 0 };
	}

	namespace ImageSpaceManager
	{
		inline constexpr REL::RelocationID Singleton{ 161743, 2712627 }; 
	}

	namespace ImageSpaceModifierInstance
	{
		inline constexpr REL::RelocationID Stop{ 0, 2199897 };
	}

	namespace ImageSpaceModifierInstanceDOF
	{
		inline constexpr REL::RelocationID Trigger{ 0, 2199922 };
	}

	namespace ImageSpaceModifierInstanceForm
	{
		inline constexpr REL::RelocationID Trigger1{ 0, 2199906 };
		inline constexpr REL::RelocationID Trigger2{ 0, 2199907 };
		inline constexpr REL::RelocationID Stop1{ 0, 2199909 };
		inline constexpr REL::RelocationID Stop2{ 0, 2199910 };
	}

	namespace IMenu
	{
		inline constexpr REL::RelocationID ShouldHandleEvent{ 0, 2287392 };
		inline constexpr REL::RelocationID PassesRenderConditionText{ 0, 2287379 };
		inline constexpr REL::RelocationID OnSetSafeRect{ 0, 2287375 };
		inline constexpr REL::RelocationID ProcessScaleformEvent{ 0, 2287395 };
		inline constexpr REL::RelocationID RefreshPlatform{ 0, 2287374 };
	}

	namespace Interface3D
	{
		inline constexpr REL::RelocationID Create{ 0, 2222519 };
		inline constexpr REL::RelocationID GetByName{ 0, 2222524 };
		inline constexpr REL::RelocationID MainScreen_AddPointLight{ 0, 2222531 };
		inline constexpr REL::RelocationID MainScreen_AddSpotLight{ 0, 2222532 };
		inline constexpr REL::RelocationID MainScreen_ClearLights{ 0, 2222533 };
		inline constexpr REL::RelocationID MainScreen_SetScreenAttached3D{ 0, 2222528 };
		inline constexpr REL::RelocationID MainScreen_SetWorldAttached3D{ 0, 2222529 };
		inline constexpr REL::RelocationID Offscreen_AddLight{ 0, 2222543 };
		inline constexpr REL::RelocationID Offscreen_Clear3D{ 0, 2222542 };
		inline constexpr REL::RelocationID Offscreen_ClearLights{ 0, 2222545 };
		inline constexpr REL::RelocationID Offscreen_GetRenderTargetHeight{ 0, 2222538 };
		inline constexpr REL::RelocationID Offscreen_GetRenderTargetWidth{ 0, 2222537 };
		inline constexpr REL::RelocationID Offscreen_Set3D{ 0, 2222541 };
		inline constexpr REL::RelocationID Offscreen_SetDebugMode{ 0, 2222549 };
		inline constexpr REL::RelocationID Offscreen_SetDirectionalLight{ 0, 2222544 };
		inline constexpr REL::RelocationID Enable{ 0, 2222522 };
		inline constexpr REL::RelocationID Disable{ 0, 2222523 };
		inline constexpr REL::RelocationID DisableAll{ 0, 2222521 };
		inline constexpr REL::RelocationID Release{ 0, 2222520 };
		inline constexpr REL::RelocationID SetViewport{ 0, 2222552 };
	}

	namespace Inventory3DManager
	{
		inline constexpr REL::RelocationID Begin3D{ 0, 2249084 };
		inline constexpr REL::RelocationID ClearModel{ 0, 2249113 };
		inline constexpr REL::RelocationID DisableRendering{ 255893, 0 };
		inline constexpr REL::RelocationID EnableRendering{ 176578, 0 };
		inline constexpr REL::RelocationID End3D{ 1512675, 0 };
		inline constexpr REL::RelocationID SetModelScale{ 1319701, 0 };
		inline constexpr REL::RelocationID SetModelScreenPosition{ 0, 2249096 };
	}

	namespace InventoryItemDisplayData
	{
		inline constexpr REL::RelocationID ctor{ 0, 2222612 };
	}

	namespace InventoryUserUIUtils
	{
		inline constexpr REL::RelocationID AddItemCardInfoEntry{ 0, 2222648 };
	}

	namespace ItemCrafted
	{
		inline constexpr REL::RelocationID NotifyOfItemCrafted{ 788895, 2232809 }; 
		inline constexpr REL::RelocationID RegisterSink{ 1320496, 2232807 }; 
		inline constexpr REL::RelocationID UnregisterSink{ 1054567, 2232808 }; 
	}

	namespace LevelIncrease
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2233736 };
	}

	namespace LoadingMenu
	{
		inline constexpr REL::RelocationID StartTestingLoadMenu{ 0, 2249224 };
	}

	namespace LockpickingMenu
	{
		inline constexpr REL::RelocationID OpenLockpickingMenu{ 129892, 0 };
	}

	namespace LocksPicked
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2249292 };
	}

	namespace MagicTarget
	{
		inline constexpr REL::RelocationID IsTakingHealthDamageFromActiveEffect{ 999442, 2226397 }; 
		inline constexpr REL::RelocationID IsTakingRadDamageFromActiveEffect{ 1079111, 2226398 }; 
	}

	namespace Main
	{
		inline constexpr REL::RelocationID Singleton{ 756304, 2698043 }; 
		inline constexpr REL::RelocationID WorldRootCamera{ 384264, 2228956 }; 
		inline constexpr REL::RelocationID QGameSystemsShouldUpdate{ 0, 2698031 };
		inline constexpr REL::RelocationID QGameDataLoaded{ 0, 2698032 }; 
		inline constexpr REL::RelocationID SetCameraFOV{ 0, 2228973 };
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::RelocationID ctor{ 1571567, 2267865 }; 
			inline constexpr REL::RelocationID dtor{ 68625, 2267867 }; 
		}

		inline constexpr REL::RelocationID Singleton{ 343176, 2193197 }; 
		inline constexpr REL::RelocationID Allocate{ 652767, 2267872 }; 
		inline constexpr REL::RelocationID Deallocate{ 1582181, 2267874 }; 
		inline constexpr REL::RelocationID GetThreadScrapHeap{ 1495205, 2267850 }; 
		inline constexpr REL::RelocationID Reallocate{ 1502917, 2267873 }; 
		inline constexpr REL::RelocationID RegisterMemoryManager{ 453212, 2228356 }; 
	}

	namespace MenuControls
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689089 };
	}

	namespace MenuCursor
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2696546 };
		inline constexpr REL::RelocationID CenterCursor{ 0, 2287473 };
		inline constexpr REL::RelocationID RegisterCursor{ 1318193, 0 };
		inline constexpr REL::RelocationID SetCursorConstraintsRaw{ 907092, 0 };
		inline constexpr REL::RelocationID UnregisterCursor{ 1225249, 0 };
		inline constexpr REL::RelocationID PipboyConstraintTLX{ 60674, 0 };
		inline constexpr REL::RelocationID PipboyConstraintTLY{ 719279, 0 };
		inline constexpr REL::RelocationID PipboyConstraintWidth{ 1376729, 0 };
		inline constexpr REL::RelocationID PipboyConstraintHeight{ 452591, 0 };
		inline constexpr REL::RelocationID PipboyConstraintTLX_PowerArmor{ 1110986, 0 };
		inline constexpr REL::RelocationID PipboyConstraintTLY_PowerArmor{ 187113, 0 };
		inline constexpr REL::RelocationID PipboyConstraintWidth_PowerArmor{ 844985, 0 };
		inline constexpr REL::RelocationID PipboyConstraintHeight_PowerArmor{ 1503497, 0 };
	}

	namespace MenuTopicManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689089 };
	}

	namespace MessageBoxMenu
	{
		inline constexpr REL::RelocationID ShowMessage{ 442479, 0 };
	}

	namespace MessageMenuManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689087 };
		inline constexpr REL::RelocationID Create{ 0, 2249456 };
	}

	namespace NiAlphaProperty
	{
		inline constexpr REL::RelocationID SetDestBlendMode{ 725249, 0 };
		inline constexpr REL::RelocationID SetSrcBlendMode{ 976961, 0 };
		inline constexpr REL::RelocationID SetTestMode{ 976961, 0 };
		inline constexpr REL::RelocationID SetAlphaBlending{ 645586, 0 };
		inline constexpr REL::RelocationID SetAlphaTesting{ 645586, 0 };
	}

	namespace NiCamera
	{
		inline constexpr REL::RelocationID WorldPtToScreenPt3{ 0, 2270344 };
	}

	namespace NiControllerManager
	{
		inline constexpr REL::RelocationID GetNiControllerManager{ 0, 2271798 };
		inline constexpr REL::RelocationID GetSequenceByName{ 846648, 0 };
	}

	namespace NiControllerSequence
	{
		inline constexpr REL::RelocationID Activate{ 0, 2271861 };
	}

	namespace NiMatrix3
	{
		inline constexpr REL::RelocationID ToEulerAnglesXYZ1{ 0, 2269806 };
		inline constexpr REL::RelocationID ToEulerAnglesXZY2{ 0, 2269807 };
		inline constexpr REL::RelocationID ToEulerAnglesYXZ3{ 0, 2269808 };
		inline constexpr REL::RelocationID ToEulerAnglesYZX4{ 0, 2269809 };
		inline constexpr REL::RelocationID ToEulerAnglesZYX5{ 0, 2269810 };
		inline constexpr REL::RelocationID ToEulerAnglesZXY6{ 0, 2269824 };
		inline constexpr REL::RelocationID FromEulerAnglesXYZ1{ 0, 2269813 };
		inline constexpr REL::RelocationID FromEulerAnglesXZY2{ 0, 2269814 };
		inline constexpr REL::RelocationID FromEulerAnglesYXZ3{ 0, 2269815 };
		inline constexpr REL::RelocationID FromEulerAnglesYZX4{ 0, 2269816 };
		inline constexpr REL::RelocationID FromEulerAnglesZYX5{ 0, 2269817 };
		inline constexpr REL::RelocationID FromEulerAnglesZXY6{ 0, 2269825 };
	}

	namespace NiNode
	{
		inline constexpr REL::RelocationID ChildrenVTable{ 390064, 0 };
	}

	namespace NiPoint
	{
		namespace NiPoint3
		{
		inline constexpr REL::RelocationID GetZAngleFromVector{ 1450064, 0 };
		}
	}

	namespace NiRefObject
	{
		inline constexpr REL::RelocationID Objects{ 1161724, 0 };
	}

	namespace NiTexture
	{
		inline constexpr REL::RelocationID SetAllowDegrade{ 0, 2270148 };
	}

	namespace nsStatsMenuUtils
	{
		inline constexpr REL::RelocationID GetEffectDisplayInfo{ 294691, 0 };
	}

	namespace PerkPointIncreaseEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2697359 };
	}

	namespace PerkUtilities
	{
		inline constexpr REL::RelocationID RemoveGrenadeTrajectory{ 672186, 0 };
	}

	namespace PipboyDataManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2689086 };
	}

	namespace PipboyInventoryData
	{
		inline constexpr REL::RelocationID RepopulateItemCardsOnSection{ 0, 2225279 };
		inline constexpr REL::RelocationID PopulateItemCardInfo{ 0, 2225266 };
		inline constexpr REL::RelocationID AddItemCardInfoEntry{ 0, 2225267 };
	}

	namespace PipboyInventoryMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 0, 2224143 };
		inline constexpr REL::RelocationID SetQuickkey{ 0, 2224159 };
	}

	namespace PipboyInventoryUtils
	{
		inline constexpr REL::RelocationID DoSlotsOverlap{ 1035436, 0 };
		inline constexpr REL::RelocationID FillDamageTypeInfo{ 928518, 0 };
		inline constexpr REL::RelocationID FillResistTypeInfo{ 1578434, 0 };
	}

	namespace PipboyLightEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1140080, 2696280 }; 
	}

	namespace PipboyLogMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 672256, 0 };
	}

	namespace PipboyManager
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2691945 };
		inline constexpr REL::RelocationID AddMenuToPipboy{ 0, 2225453 };
		inline constexpr REL::RelocationID ClosedownPipboy{ 0, 2225480 };
		inline constexpr REL::RelocationID EnablePipboyShader{ 0, 2225484 };
		inline constexpr REL::RelocationID InitPipboy{ 0, 2225479 };
		inline constexpr REL::RelocationID LowerPipboy{ 0, 2225454 };
		inline constexpr REL::RelocationID OnPipboyCloseAnim{ 0, 2225457 };
		inline constexpr REL::RelocationID OnPipboyCloseAnimFailed{ 0, 2225459 };
		inline constexpr REL::RelocationID OnPipboyClosed{ 0, 2225458 };
		inline constexpr REL::RelocationID OnPipboyOpenAnim{ 0, 2225448 };
		inline constexpr REL::RelocationID OnPipboyOpenAnimFailed{ 0, 2225449 };
		inline constexpr REL::RelocationID OnPipboyOpened{ 0, 2225450 };
		inline constexpr REL::RelocationID PlayItemAnimOnClose{ 0, 2225461 };
		inline constexpr REL::RelocationID PlayPipboyCloseAnim{ 0, 2225456 };
		inline constexpr REL::RelocationID PlayPipboyGenericOpenAnim{ 0, 2225447 };
		inline constexpr REL::RelocationID PlayPipboyLoadHolotapeAnim{ 0, 2225446 };
		inline constexpr REL::RelocationID PlayPipboyOpenAnim{ 0, 2225444 };
		inline constexpr REL::RelocationID PlayPipboyOpenTerminalAnim{ 0, 2225445 };
		inline constexpr REL::RelocationID ProcessLoweringReason{ 0, 2225486 };
		inline constexpr REL::RelocationID QPipboyActive{ 0, 2225460 };
		inline constexpr REL::RelocationID RaisePipboy{ 0, 2225455 };
		inline constexpr REL::RelocationID RefreshPipboyRenderSurface{ 0, 2225478 };
		inline constexpr REL::RelocationID StartAnimationGraphListening{ 0, 2225490 };
		inline constexpr REL::RelocationID StopAnimationGraphListening{ 0, 2225491 };
		inline constexpr REL::RelocationID UpdateCursorConstraint{ 0, 2225488 };
	}

	namespace PipboyMapMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 0, 2224074 };
	}

	namespace PipboyMenu
	{
		inline constexpr REL::RelocationID RefreshMapMarkers{ 0, 2224187 };
	}

	namespace PipboyObject
	{
		inline constexpr REL::RelocationID AddMember{ 0, 2225699 };
	}

	namespace PipboyPerksMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 783380, 0 };
	}

	namespace PipboyPlayerInfoMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 426990, 0 };
	}

	namespace PipboyPrimitiveValue
	{
		namespace uint32
		{
			inline constexpr REL::RelocationID ctor{ 0, 2225324 };
		}

		namespace boolean
		{
			inline constexpr REL::RelocationID ctor{ 0, 2225327 };
		}
	}

	namespace PipboyQuestMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 0, 2224231 };
	}

	namespace PipboyRadioMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 713423, 0 };
	}

	namespace PipboySpecialMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 1426810, 0 };
	}

	namespace PipboyStatsMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 332518, 0 };
	}

	namespace PipboySubMenu
	{
		inline constexpr REL::RelocationID ProcessEvent{ 893703, 0 };
	}

	namespace PipboyValue
	{
		inline constexpr REL::RelocationID ctor{ 0, 2225915 };
	}

	namespace PipboyWorkshopMenu
	{
		inline constexpr REL::RelocationID UpdateData{ 0, 2224273 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::RelocationID Singleton{ 1171980, 2688801 }; 
		inline constexpr REL::RelocationID PopState{ 120998, 2248424 }; 
		inline constexpr REL::RelocationID PushState{ 0, 2248422 };
		inline constexpr REL::RelocationID ToggleFreeCameraMode{ 224913, 2248368 }; 
		inline constexpr REL::RelocationID SetState{ 858847, 2214742 }; 
		inline constexpr REL::RelocationID StartFurnitureMode{ 0, 2248373 };
		inline constexpr REL::RelocationID StartPipboyMode{ 998069, 2248358 }; 
		inline constexpr REL::RelocationID StopPipboyMode{ 811954, 2248359 }; 
		inline constexpr REL::RelocationID QCameraEquals{ 839543, 2248421 }; 
	}

	namespace PlayerCharacter
	{
		namespace ScopedInventoryChangeMessageContext
		{
			inline constexpr REL::RelocationID ctor{ 0, 2233292 };
			inline constexpr REL::RelocationID dtor{ 0, 2233293 };
		}

		inline constexpr REL::RelocationID Singleton{ 303410, 2690919 }; 
		inline constexpr REL::RelocationID GetPlayerHandle{ 522947, 2698072 }; 
		inline constexpr REL::RelocationID GetDifficultyLevel{ 922962, 2233056 }; 
		inline constexpr REL::RelocationID IsGodMode{ 1032309, 2232986 }; 
		inline constexpr REL::RelocationID IsHolotapePlaying{ 530826, 2233206 }; 
		inline constexpr REL::RelocationID IsImmortal{ 500346, 2232988 }; 
		inline constexpr REL::RelocationID IsPipboyLightOn{ 0, 2233202 };
		inline constexpr REL::RelocationID PauseHolotape{ 1567456, 2233208 }; 
		inline constexpr REL::RelocationID PlayHolotape{ 1581042, 2233207 }; 
		inline constexpr REL::RelocationID QueueFastTravel{ 0, 2232918 };
		inline constexpr REL::RelocationID RemoveLastUsedPowerArmor{ 0, 2233024 };
		inline constexpr REL::RelocationID SelectPerk{ 0, 2232926 };
		inline constexpr REL::RelocationID SetEscaping{ 0, 2233142 };
		inline constexpr REL::RelocationID SetVATSCriticalCount{ 0, 2233219 };
		inline constexpr REL::RelocationID ShowPipboyLight{ 0, 2233203 };
		inline constexpr REL::RelocationID SetLastDialogueInput{ 696117, 2233190 }; 
		inline constexpr REL::RelocationID ClearPrison{ 0, 2233196 }; 
		inline constexpr REL::RelocationID ReloadWeapon{ 0, 2232907 };
		inline constexpr REL::RelocationID SetPerkCount{ 0, 2233187 };
	}

	namespace PlayerControls
	{
		inline constexpr REL::RelocationID Singleton{ 544871, 2692013 };
		inline constexpr REL::RelocationID CanPerformAction{ 565925, 0 };
		inline constexpr REL::RelocationID DoAction{ 818081, 0 };
		inline constexpr REL::RelocationID DoRegisterHandler{ 177801, 2234822 };
	}

	namespace PowerArmor
	{
		inline constexpr REL::RelocationID ActorInPowerArmor{ 1176757, 2219437 }; 
		inline constexpr REL::RelocationID GetArmorKeyword{ 961172, 0 };
		inline constexpr REL::RelocationID GetBatteryKeyword{ 1493537, 0 };
		inline constexpr REL::RelocationID GetDefaultBatteryObject{ 1279247, 0 };
		inline constexpr REL::RelocationID IsPowerArmorBattery{ 1012910, 0 };
		inline constexpr REL::RelocationID SyncFurnitureVisualsToInventory{ 1078979, 0 };
		inline constexpr REL::RelocationID fNewBatteryCapacity{ 1134204, 0 };
	}

	namespace PowerArmorGeometry
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2694441 };
		inline constexpr REL::RelocationID HidePipboyPAGeometry{ 0, 2248877 };
		inline constexpr REL::RelocationID ShowPipboyPAGeometry{ 0, 2248876 };
	}

	namespace PowerArmorLightData
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2701547 };
	}

	namespace ProcessLists
	{
		inline constexpr REL::RelocationID Singleton{ 1569706, 2688869 }; 
		inline constexpr REL::RelocationID AreHostileActorsNear{ 1053584, 2234105 }; 
		inline constexpr REL::RelocationID IsActorTargetingREFinPackage{ 559542, 2234033 }; 
		inline constexpr REL::RelocationID RequestHighestDetectionLevelAgainstActor{ 1036693, 2234111 }; 
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::RelocationID GetLockLevel{ 0, 2191018 };
		inline constexpr REL::RelocationID SetLocked{ 0, 2191020 };
		inline constexpr REL::RelocationID IsBroken{ 0, 2191021 };
	}

	namespace ScrapHeap
	{
		inline constexpr REL::RelocationID Allocate{ 1085394, 2267983 }; 
		inline constexpr REL::RelocationID Deallocate{ 923307, 2267984 }; 
	}

	namespace SCRIPT_FUNCTION
	{
		inline constexpr REL::RelocationID ConsoleFunctions{ 901511, 0 };
		inline constexpr REL::RelocationID ScriptFunctions{ 75173, 0 };
		inline constexpr REL::RelocationID CompileFunction{ 638606, 2204343 }; 
	}

	namespace Script
	{
		inline constexpr REL::RelocationID ParseParameters{ 1607, 2204298 }; 
		inline constexpr REL::RelocationID CompileAndRun{ 526625, 2204287 }; 
		inline constexpr REL::RelocationID GetProcessScripts{ 44950, 2204310 }; 
		inline constexpr REL::RelocationID SetProcessScripts{ 1188642, 2204309 }; 
	}

	namespace SendHUDMessage
	{
		inline constexpr REL::RelocationID PopHUDMode{ 0, 2222444 };
		inline constexpr REL::RelocationID PushHUDMode{ 0, 2222443 };
		inline constexpr REL::RelocationID SetPowerArmorMode{ 361745, 0 };
		inline constexpr REL::RelocationID ShowHUDMessage{ 1163005, 2222440 }; 
	}

	namespace Setting
	{
		namespace INISettingCollection
		{
			inline constexpr REL::RelocationID Singleton{ 791183, 2704108 }; 
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::RelocationID Singleton{ 767844, 2703234 }; 
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::RelocationID InitCollection{ 948832, 2188690 }; 
			inline constexpr REL::RelocationID Singleton{ 8308, 2690301 }; 
		}
	}

	namespace SitWaitMenu
	{
		inline constexpr REL::RelocationID OnEnterFurniture{ 0, 2249503 };
		inline constexpr REL::RelocationID OnExitFurniture{ 0, 2249504 };
	}

	namespace Sky
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2192448 };
		inline constexpr REL::RelocationID ForceWeather{ 0, 2208861 };
		inline constexpr REL::RelocationID ResetWeather{ 0, 2208860 };
	}

	namespace SplineUtils
	{
		inline constexpr REL::RelocationID DisconnectSpline{ 750682, 0 };
		inline constexpr REL::RelocationID ConnectSpline{ 59311, 0 };
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::RelocationID MapCodeMethodToASFunction{ 1263128, 2287419 }; 
		inline constexpr REL::RelocationID RegisterCodeObject{ 67637, 2287415 }; 
	}

	namespace TaskQueueInterface
	{
		inline constexpr REL::RelocationID Singleton{ 7491, 0 };
		inline constexpr REL::RelocationID QueueClosePipboy{ 69886, 0 };
		inline constexpr REL::RelocationID QueueRebuildBendableSpline{ 198419, 0 };
		inline constexpr REL::RelocationID QueueShow1stPerson{ 994377, 0 };
		inline constexpr REL::RelocationID QueueShowPipboy{ 1133684, 0 };
		inline constexpr REL::RelocationID QueueUpdate3D{ 581890, 0 };
		inline constexpr REL::RelocationID QueueWeaponFire{ 15449, 0 };
	}

	namespace TerminalHacked
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2233751 };
	}

	namespace TES
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2698044 };
	}

	namespace TESActivateEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 166230, 0 };
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::RelocationID GetLevel{ 151866, 2192891 }; 
	}

	namespace TESAmmo
	{
		inline constexpr REL::RelocationID GetReloadsWithAmmoRef{ 1035622, 2197864 }; 
	}

	namespace TESBoundObject
	{
		inline constexpr REL::RelocationID ApplyMods{ 113585, 2198325 }; 
	}

	namespace TESCellAttachDetachEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201823 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201824 };
	}

	namespace TESCondition
	{
		inline constexpr REL::RelocationID IsTrue{ 1275731, 2211989 }; 
		inline constexpr REL::RelocationID IsTrueForAllButFunction{ 1182457, 0 };
		inline constexpr REL::RelocationID ClearAllConditionItems{ 0, 2211988 };
	}

	namespace TESConditionItem
	{
		inline constexpr REL::RelocationID GetComparisonValue{ 1373349, 2212007 }; 
		inline constexpr REL::RelocationID IsTrue1{ 1453240, 2212008 }; 
		inline constexpr REL::RelocationID IsTrue2{ 0, 2212009 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 242538, 0 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::RelocationID Singleton{ 711558, 2688883 }; 
		inline constexpr REL::RelocationID AddFormToDataHandler{ 350112, 2192271 }; 
		inline constexpr REL::RelocationID CheckModsLoaded{ 1432894, 2192323 }; 
		inline constexpr REL::RelocationID CreateReferenceAtLocation{ 0, 2192301 };
		inline constexpr REL::RelocationID IsFormIDInuse{ 1448838, 2192351 }; 
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1465690, 2201833 }; 
	}

	namespace TESDescription
	{
		inline constexpr REL::RelocationID GetDescription{ 0, 2193019 };
	}

	namespace TESEnterSneakingEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201837 };
	}

	namespace TESFile
	{
		inline constexpr REL::RelocationID CloseTES{ 766555, 2192491 }; 
		inline constexpr REL::RelocationID GetChunkData{ 188910, 2192538 }; 
		inline constexpr REL::RelocationID GetTESChunk{ 641361, 2192536 }; 
		inline constexpr REL::RelocationID NextChunk{ 1252764, 2192537 }; 
		inline constexpr REL::RelocationID NextForm{ 644374, 2192527 }; 
		inline constexpr REL::RelocationID NextGroup{ 339855, 2192522 }; 
		inline constexpr REL::RelocationID OpenTES{ 728465, 2192490 }; 
	}

	namespace TESForm
	{
		inline constexpr REL::RelocationID FormSortFunc{ 705530, 0 };
		inline constexpr REL::RelocationID AddCompileIndex{ 1315637, 2193152 }; 
		inline constexpr REL::RelocationID AllForms{ 422985, 2689178 }; 
		inline constexpr REL::RelocationID AllFormsMapLock{ 691815, 2689189 }; 
		inline constexpr REL::RelocationID AllFormsByEditorID{ 642758, 2689179 }; 
		inline constexpr REL::RelocationID AllFormsEditorIDMapLock{ 910917, 2689190 }; 
		inline constexpr REL::RelocationID GetFile{ 1376557, 2193103 }; 
		inline constexpr REL::RelocationID GetFormEnumString{ 1309967, 0 };
		inline constexpr REL::RelocationID GetFormTypeFromString{ 565203, 2193108 }; 
		inline constexpr REL::RelocationID SetTemporary{ 0, 2193125 };
	}

	namespace TESFormDeleteEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1396562, 2201842 }; 
	}

	namespace TESFullName
	{
		inline constexpr REL::RelocationID SparseFullNameMap{ 226372, 2661402 }; 
	}

	namespace TESFurniture
	{
		inline constexpr REL::RelocationID GetContainer{ 1049933, 2198043 }; 
	}

	namespace TESFurnitureEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 678665, 2201844 }; 
	}

	namespace TESHarvestEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2193351 };
	}

	namespace TESHealthForm
	{
		inline constexpr REL::RelocationID GetFormHealth{ 0, 2193227 };
	}

	namespace TESHitEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201886 };
	}

	namespace TESInitScriptEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201846 };
	}

	namespace TESLeveledList
	{
		inline constexpr REL::RelocationID AddLeveledObject{ 0, 2193258 };
		inline constexpr REL::RelocationID CalculateCurrentFormList{ 0, 2193259 };
		inline constexpr REL::RelocationID CalculateCurrentFormListForRef{ 507405, 2193260 }; 
		inline constexpr REL::RelocationID GetUseAll{ 0, 2193253 };
	}

	namespace TESLoadGameEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 0, 2201848 };
	}

	namespace TESMagicEffectApplyEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1481228, 1327824 }; 
	}

	namespace TESNPC
	{
		inline constexpr REL::RelocationID AlternateHeadPartListMap{ 0, 2662368 };
		inline constexpr REL::RelocationID GetSex{ 1257181, 2207107 }; 
		inline constexpr REL::RelocationID GetFacialBoneMorphIntensity{ 272217, 2207416 }; 
		inline constexpr REL::RelocationID SetHairColor{ 0, 2207426 };
	}

	namespace TESObjectCELL
	{
		inline constexpr REL::RelocationID GetbhkWorld{ 0, 2200260 };
		inline constexpr REL::RelocationID GetCantWaitHere{ 376940, 2200287 }; 
		inline constexpr REL::RelocationID GetDataX{ 445210, 2200213 }; 
		inline constexpr REL::RelocationID GetDataY{ 1322816, 2200214 }; 
		inline constexpr REL::RelocationID GetEncounterZone{ 1414637, 2200242 }; 
		inline constexpr REL::RelocationID GetLocation{ 868663, 2200179 }; 
		inline constexpr REL::RelocationID GetOwner{ 0, 2200236 };
		inline constexpr REL::RelocationID GetRegionList{ 1565031, 2200265 }; 
		inline constexpr REL::RelocationID Pick{ 0, 2200263 };
		inline constexpr REL::RelocationID SetCullCellMarkers{ 0, 2192259 };
		inline constexpr REL::RelocationID UpdateAllRefsLoaded{ 0, 2200415 };
		inline constexpr REL::RelocationID AttatchReference3D{ 0, 2200620 };
		inline constexpr REL::RelocationID RemoveReference{ 0, 2200299 };
		inline constexpr REL::RelocationID UpdateAllDecals{ 0, 2200643 };
		inline constexpr REL::RelocationID DefaultWater{ 0, 2691845 };
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 416662, 2201853 }; 
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::RelocationID ActivateRef{ 0, 2201147 };
		inline constexpr REL::RelocationID AddInventoryItem{ 0, 2200949 };
		inline constexpr REL::RelocationID AddKeyword{ 640674, 2200860 }; 
		inline constexpr REL::RelocationID AddLockChange{ 1578706, 0 };
		inline constexpr REL::RelocationID ApplyArtObject{ 0, 2205200 };
		inline constexpr REL::RelocationID ApplyEffectShader{ 0, 2205201 };
		inline constexpr REL::RelocationID Enable{ 1396707, 0 };
		inline constexpr REL::RelocationID GetCurrentLocation{ 1135470, 2201163 }; 
		inline constexpr REL::RelocationID GetDisplayFullName{ 1212056, 2201126 }; 
		inline constexpr REL::RelocationID GetEditorDead{ 0, 2200781 };
		inline constexpr REL::RelocationID GetOwner{ 1323437, 0 };
		inline constexpr REL::RelocationID GetGoldAmount{ 0, 2200923 };
		inline constexpr REL::RelocationID GetHandle{ 1573130, 2201196 }; 
		inline constexpr REL::RelocationID GetHasOwner{ 1016277, 0 };
		inline constexpr REL::RelocationID GetInventoryObjectCount{ 0, 2200939 };
		inline constexpr REL::RelocationID GetLinkedRef{ 897287, 0 };
		inline constexpr REL::RelocationID GetLock{ 930785, 0 };
		inline constexpr REL::RelocationID GetWeightInContainer{ 0, 2201001 };
		inline constexpr REL::RelocationID HasContainer{ 0, 2201022 };
		inline constexpr REL::RelocationID IsAnOwner{ 933798, 0 };
		inline constexpr REL::RelocationID IsCrimeToActivate{ 0, 2201180 };
		inline constexpr REL::RelocationID IsInWater{ 315318, 0 };
		inline constexpr REL::RelocationID IsLeveledCreature{ 1341859, 2202655 }; 
		inline constexpr REL::RelocationID MarkAsDeleted{ 192661, 0 };
		inline constexpr REL::RelocationID MoveRefToNewSpace{ 629658, 0 };
		inline constexpr REL::RelocationID RemoveKeyword{ 0, 2200861 };
		inline constexpr REL::RelocationID SetAngleOnReference{ 1049748, 0 };
		inline constexpr REL::RelocationID SetLinkedRef{ 192840, 0 };
		inline constexpr REL::RelocationID SetLocationOnReference{ 1101832, 0 };
		inline constexpr REL::RelocationID SetWantsDelete{ 761346, 0 };
		inline constexpr REL::RelocationID RebuildBendableSpline{ 340319, 0 };
		inline constexpr REL::RelocationID GetItemCount{ 0, 2200996 };
		inline constexpr REL::RelocationID UpdateReference3D{ 1568075, 0 };
		inline constexpr REL::RelocationID GetObjectCenter{ 777738, 0 };
		inline constexpr REL::RelocationID SetScale{ 0, 2200893 };
		inline constexpr REL::RelocationID IsMarker{ 0, 2201157 };
		inline constexpr REL::RelocationID IsDecalRef{ 0, 2200794 }; 
	}

	namespace TESObjectWEAP
	{
		inline constexpr REL::RelocationID GetMeleeAttackSpeed{ 0, 2198957 };
		inline constexpr REL::RelocationID GetMeleeAttackSpeedLabel{ 0, 2198959 };
	}

	namespace TESQuest
	{
		inline constexpr REL::RelocationID SetStage{ 952799, 2207743 }; 
		inline constexpr REL::RelocationID GetAliasedRef{ 847223, 2207810 }; 
	}

	namespace TESResponse
	{
		inline constexpr REL::RelocationID GetResponseText{ 0, 2208288 };
		inline constexpr REL::RelocationID GetSpeakerIdle{ 0, 2208293 };
	}

	namespace TESSpellList
	{
		inline constexpr REL::RelocationID AddSpell{ 1312083, 0 };
	}

	namespace TESSwitchRaceCompleteEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 609604, 2201874 };
	}

	namespace TESTopicInfo
	{
		inline constexpr REL::RelocationID GetParentInfoGroup{ 163538, 2208435 }; 
		inline constexpr REL::RelocationID GetChallengeLevel{ 0, 2208441 }; 
		inline constexpr REL::RelocationID GetSuccessLevel{ 1023955, 2208444 }; 
		inline constexpr REL::RelocationID StartSceneOnEnd{ 0, 2208466 };
		inline constexpr REL::RelocationID GetScene{ 0, 2208453 };
		inline constexpr REL::RelocationID StartScene{ 0, 2208469 };
	}

	namespace TESValueForm
	{
		inline constexpr REL::RelocationID GetFormValue{ 0, 2193435 };
	}

	namespace TESWeightForm
	{
		inline constexpr REL::RelocationID GetFormWeight{ 0, 2193446 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::RelocationID DefaultWater{ 0, 2691845 };
	}

	namespace UI
	{
		inline constexpr REL::RelocationID CustomRendererHasQuads{ 0, 2284757 };
		inline constexpr REL::RelocationID GetMenuMapRWLock{ 578487, 2707105 }; 
		inline constexpr REL::RelocationID Singleton{ 548587, 2689028 }; 
		inline constexpr REL::RelocationID RefreshCursor{ 0, 2284772 };
		inline constexpr REL::RelocationID RegisterMenu{ 0, 2284766 };
		inline constexpr REL::RelocationID UpdateControllerType{ 0, 2284768 };
	}

	namespace UIAdvanceMenusFunctionCompleteEvent
	{
		inline constexpr REL::RelocationID GetEventSource{ 1067039, 0 };
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::RelocationID Singleton{ 82123, 2689091 }; 
		inline constexpr REL::RelocationID AddMessage{ 1182019, 2284929 }; 
	}

	namespace UIUtils
	{
		inline constexpr REL::RelocationID GetComparisonItems{ 593818, 0 };
		inline constexpr REL::RelocationID PlayPipboySound{ 0, 2249706 };
		inline constexpr REL::RelocationID PlayMenuSound{ 0, 2249707 };
		inline constexpr REL::RelocationID UpdateGamepadDependentButtonCodes{ 0, 2249714 };
	}

	namespace VATS
	{
		inline constexpr REL::RelocationID Singleton{ 0, 2690444 };
	}

	namespace WorkbenchMenuBase
	{
		inline constexpr REL::RelocationID UpdateOptimizedAutoBuildInv{ 0, 2224955 };
	}

	namespace Workshop
	{
		namespace PlacementItemData
		{
		inline constexpr REL::RelocationID Set{ 1460935, 0 };
		}

		namespace WorkshopMenuNode
		{
		inline constexpr REL::RelocationID FindAndSetSelectedNode{ 1309368, 0 };
		}

		inline constexpr REL::RelocationID FindNearestValidWorkshop{ 905705, 2194970 }; 
		inline constexpr REL::RelocationID FreeBuild{ 1583365, 2194924 }; 
		inline constexpr REL::RelocationID GetSelectedWorkshopMenuNode{ 763948, 2195024 }; 
		inline constexpr REL::RelocationID InitializePlacementReference{ 1577199, 0 };
		inline constexpr REL::RelocationID IsLocationWithinBuildableArea{ 990965, 0 };
		inline constexpr REL::RelocationID PlaceCurrentReference{ 1058211, 0 };
		inline constexpr REL::RelocationID RegisterForItemDestroyed{ 1367004, 0 };
		inline constexpr REL::RelocationID RegisterForItemMoved{ 835323, 0 };
		inline constexpr REL::RelocationID RegisterForItemPlaced{ 849008, 0 };
		inline constexpr REL::RelocationID RegisterForWorkshopModeEvent{ 275798, 0 };
		inline constexpr REL::RelocationID RequestExitWorkshop{ 209891, 0 };
		inline constexpr REL::RelocationID ScrapReference{ 636327, 0 };
		inline constexpr REL::RelocationID SetSelectedEditItem{ 2562, 0 };
		inline constexpr REL::RelocationID StartWorkshop{ 0, 2195134 };
		inline constexpr REL::RelocationID ToggleEditMode{ 1243386, 0 };
		inline constexpr REL::RelocationID UnregisterForItemDestroyed{ 1101379, 0 };
		inline constexpr REL::RelocationID UnregisterForItemMoved{ 569432, 0 };
		inline constexpr REL::RelocationID UnregisterForItemPlaced{ 583255, 0 };
		inline constexpr REL::RelocationID UnregisterForWorkshopModeEvent{ 9236, 0 };
		inline constexpr REL::RelocationID UpdateActiveEdit{ 69261, 0 };
		inline constexpr REL::RelocationID WorkshopCanShowRecipe{ 239190, 0 };
		inline constexpr REL::RelocationID CurrentPlacementItemData{ 1279207, 0 };
		inline constexpr REL::RelocationID CurrentRow{ 833923, 0 };
		inline constexpr REL::RelocationID PlacementItem{ 526727, 0 };
	}

	namespace WorkshopMenu
	{
		inline constexpr REL::RelocationID CheckAndSetItemForPlacement{ 1541862, 0 };
		inline constexpr REL::RelocationID UpdateButtonText{ 1089189, 0 };
	}

		inline constexpr REL::RelocationID NiFree{ 242362, 0 };
		inline constexpr REL::RelocationID NiMalloc{ 974443, 0 };
	inline constexpr REL::RelocationID RTDynamicCast{ 84112, 2725673 }; 
}

namespace Scaleform::ID
{
	namespace GFx::ASStringManager
	{
		inline constexpr REL::RelocationID CreateStringNode{ 0, 2290014 };
	}

	namespace GFx::Loader
	{
		inline constexpr REL::RelocationID CreateMovie{ 0, 2284723 };
	}

	namespace GFx::Movie
	{
		inline constexpr REL::RelocationID Release{ 404814, 2287230 }; 
	}

	namespace GFx::Value
	{
		inline constexpr REL::RelocationID ObjectAddRef{ 244786, 2286228 }; 
		inline constexpr REL::RelocationID ObjectRelease{ 856221, 2286229 }; 
		inline constexpr REL::RelocationID HasMember{ 0, 2286078 };
		inline constexpr REL::RelocationID GetArraySize{ 254218, 2285791 }; 
		inline constexpr REL::RelocationID GetMember{ 1517430, 2285936 }; 
		inline constexpr REL::RelocationID GetElement{ 0, 2285881 };
		inline constexpr REL::RelocationID SetElement{ 0, 2286575 };
		inline constexpr REL::RelocationID SetMember{ 1360149, 2286589 }; 
		inline constexpr REL::RelocationID Invoke{ 655847, 2286101 }; 
		inline constexpr REL::RelocationID PushBack{ 1330475, 2286424 }; 
		inline constexpr REL::RelocationID RemoveElements{ 1286586, 2286475 }; 
		inline constexpr REL::RelocationID VisitMembers{ 0, 2286786 }; 
		inline constexpr REL::RelocationID GetDisplayInfo{ 498814, 2285873 }; 
	}

	namespace Memory
	{
		inline constexpr REL::RelocationID SetGlobalHeap{ 939898, 2707353 }; 
		inline constexpr REL::RelocationID GetGlobalHeap{ 939898, 2707353 }; 
	}

	namespace SysAlloc
	{
		inline constexpr REL::RelocationID InitHeapEngine{ 0, 2284532 };
		inline constexpr REL::RelocationID ShutdownHeapEngine{ 0, 2284536 };
	}
}
