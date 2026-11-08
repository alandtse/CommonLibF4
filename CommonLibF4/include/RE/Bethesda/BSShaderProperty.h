#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiObject.h"
#include "RE/NetImmerse/NiShadeProperty.h"

namespace RE
{
	class BSEffectShaderData;
	class BSRenderPass;
	class BSShaderAccumulator;
	class BSShaderMaterial;
	class NiTexture;

	struct __declspec(novtable) BSShaderProperty :
		public NiShadeProperty  // 00
	{
	private:
		static constexpr auto BIT64 = static_cast<std::uint64_t>(1);

	public:
		static constexpr auto RTTI{ RTTI::BSShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSShaderProperty };

		enum class TextureTypeEnum
		{
			kBase = 0,
			kNormal,
			kGlow,
			kHeight,
			kEnv,
			kWrinkles,
			kMultilayer,
			kBacklightMask,
			kSmoothSpec = kBacklightMask,

			kTotal,
		};

		enum class EShaderPropertyFlag : std::uint64_t
		{
			kSpecular = BIT64 << 0,
			kSkinned = BIT64 << 1,
			kTempRefraction = BIT64 << 2,
			kVertexAlpha = BIT64 << 3,
			kGrayscaleToPaletteColor = BIT64 << 4,
			kGrayscaleToPaletteAlpha = BIT64 << 5,
			kFalloff = BIT64 << 6,
			kEnvMap = BIT64 << 7,
			kRGBFalloff = BIT64 << 8,
			kCastShadows = BIT64 << 9,
			kFace = BIT64 << 10,
			kUIMaskRects = BIT64 << 11,
			kModelSpaceNormals = BIT64 << 12,
			kRefractionClamp = BIT64 << 13,
			kMultiTextureLandscape = BIT64 << 14,
			kRefraction = BIT64 << 15,
			kRefractionFalloff = BIT64 << 16,
			kEyeReflect = BIT64 << 17,
			kHairTint = BIT64 << 18,
			kScreendoorAlphaFade = BIT64 << 19,
			kLocalMapClear = BIT64 << 20,
			kFaceGenRGBTint = BIT64 << 21,
			kOwnEmit = BIT64 << 22,
			kProjectedUV = BIT64 << 23,
			kMultipleTextures = BIT64 << 24,
			kTesselate = BIT64 << 25,
			kDecal = BIT64 << 26,
			kDynamicDecal = BIT64 << 27,
			kCharacterLight = BIT64 << 28,
			kExternalEmittance = BIT64 << 29,
			kSoftEffect = BIT64 << 30,
			kZBufferTest = BIT64 << 31,
			kZBufferWrite = BIT64 << 32,
			kLODLandscape = BIT64 << 33,
			kLODObjects = BIT64 << 34,
			kNoFade = BIT64 << 35,
			kTwoSided = BIT64 << 36,
			kVertexColors = BIT64 << 37,
			kGlowMap = BIT64 << 38,
			kTransformChanged = BIT64 << 39,
			kDismembermentMeatCuff = BIT64 << 40,
			kTint = BIT64 << 41,
			kVertexLighting = BIT64 << 42,
			kUniformScale = BIT64 << 43,
			kFitSlope = BIT64 << 44,
			kBillboard = BIT64 << 45,
			kLODLandBlend = BIT64 << 46,
			kDismemberment = BIT64 << 47,
			kWireframe = BIT64 << 48,
			kWeaponBlood = BIT64 << 49,
			kHideOnLocalMap = BIT64 << 50,
			kPremultAlpha = BIT64 << 51,
			kVATSTarget = BIT64 << 52,
			kAnisotropicLighting = BIT64 << 53,
			kSkewSpecularAlpha = BIT64 << 54,
			kMenuScreen = BIT64 << 55,
			kMultiLayerParallax = BIT64 << 56,
			kAlphaTest = BIT64 << 57,
			kInvertedFadePattern = BIT64 << 58,
			kVATSTargetDrawAll = BIT64 << 59,
			kPipboyScreen = BIT64 << 60,
			kTreeAnim = BIT64 << 61,
			kEffectLighting = BIT64 << 62,
			kRefractionWritesDepth = BIT64 << 63
		};

		class ForEachVisitor;

		class RenderPassArray
		{
		public:
			constexpr RenderPassArray() noexcept {}  // NOLINT(modernize-use-equals-default)

			// members
			BSRenderPass* passList{ nullptr };  // 0
		};
		static_assert(sizeof(RenderPassArray) == 0x8);

		// add
		RenderPassArray* GetRenderPasses(BSGeometry* a_geom, std::uint32_t a_renderMode, BSShaderAccumulator* a_accumulator)  // 2B
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetRenderPasses)>(0x2B, 0x2D, this, a_geom, a_renderMode, a_accumulator);
		}

		RenderPassArray* GetRenderPasses_ShadowMapOrMask(BSGeometry* a_geom, std::uint32_t a_renderMode, BSShaderAccumulator* a_accumulator)  // 2C
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetRenderPasses_ShadowMapOrMask)>(0x2C, 0x2E, this, a_geom, a_renderMode, a_accumulator);
		}

		RenderPassArray* GetRenderPasses_LocalMap(BSGeometry* a_geom, std::uint32_t a_renderMode, BSShaderAccumulator* a_accumulator)  // 2D
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetRenderPasses_LocalMap)>(0x2D, 0x2F, this, a_geom, a_renderMode, a_accumulator);
		}

		BSRenderPass* CreateVatsMaskRenderPass(BSGeometry* a_geom)  // 2E
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::CreateVatsMaskRenderPass)>(0x2E, 0x30, this, a_geom);
		}

		std::uint16_t GetNumberofPasses(BSGeometry* a_geom)  // 2F
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetNumberofPasses)>(0x2F, 0x31, this, a_geom);
		}

		BSRenderPass* GetRenderDepthPass(BSGeometry* a_geom)  // 30
		{
			if (REL::Module::IsVR()) {
				return nullptr;
			}
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetRenderDepthPass)>(0x30, 0x30, this, a_geom);
		}

		bool CanMerge(const BSShaderProperty* a_prop)  // 31
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::CanMerge)>(0x31, 0x32, this, a_prop);
		}

		void SetMaterialAlpha(float a_alpha)  // 32
		{
			REL::RelocateVirtual<decltype(&BSShaderProperty::SetMaterialAlpha)>(0x32, 0x33, this, a_alpha);
		}

		float QMaterialAlpha() const  // 33
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::QMaterialAlpha)>(0x33, 0x34, this);
		}

		const BSFixedString& GetRootName() const  // 34
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetRootName)>(0x34, 0x35, this);
		}

		std::int32_t ForEachTexture(ForEachVisitor& a_visitor)  // 35
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::ForEachTexture)>(0x35, 0x36, this, a_visitor);
		}

		std::int32_t QShader() const  // 36
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::QShader)>(0x36, 0x37, this);
		}

		void ClearUnusedMaterialValues()  // 37
		{
			REL::RelocateVirtual<decltype(&BSShaderProperty::ClearUnusedMaterialValues)>(0x37, 0x38, this);
		}

		BSShaderProperty* ClarifyShader(BSGeometry* a_geom, bool a_arg2, bool a_arg3)  // 38
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::ClarifyShader)>(0x38, 0x39, this, a_geom, a_arg2, a_arg3);
		}

		NiTexture* GetBaseTexture() const  // 39
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetBaseTexture)>(0x39, 0x3A, this);
		}

		RenderPassArray* GetWaterFogPassList(BSGeometry* a_geom)  // 3A
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetWaterFogPassList)>(0x3A, 0x3B, this, a_geom);
		}

		bool AcceptsEffectData() const  // 3B
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::AcceptsEffectData)>(0x3B, 0x3C, this);
		}

		void PrecacheTextures()  // 3C
		{
			REL::RelocateVirtual<decltype(&BSShaderProperty::PrecacheTextures)>(0x3C, 0x3D, this);
		}

		std::uint32_t DetermineUtilityShaderDecl() const  // 3D
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::DetermineUtilityShaderDecl)>(0x3D, 0x3E, this);
		}

		std::uint32_t GetMaterialType() const  // 3E
		{
			return REL::RelocateVirtual<decltype(&BSShaderProperty::GetMaterialType)>(0x3E, 0x3F, this);
		}

		void DoClearRenderPasses()  // 3F
		{
			REL::RelocateVirtual<decltype(&BSShaderProperty::DoClearRenderPasses)>(0x3F, 0x40, this);
		}

		void SetMaterial(BSShaderMaterial* a_material, bool a_unique)
		{
			using func_t = decltype(&BSShaderProperty::SetMaterial);
			static REL::Relocation<func_t> func{ REL::ID(706318) };
			return func(this, a_material, a_unique);
		}

		// members
		float                                            alpha;                  // 28
		std::int32_t                                     lastRenderPassState;    // 2C
		REX::EnumSet<EShaderPropertyFlag, std::uint64_t> flags;                  // 30
		RenderPassArray                                  renderPassList;         // 38
		RenderPassArray                                  debugRenderPassList;    // 40
		BSFadeNode*                                      fadeNode;               // 48
		BSEffectShaderData*                              effectData;             // 50
		BSShaderMaterial*                                material;               // 58
		std::uint32_t                                    lastAccumTime;          // 60
		float                                            lodFade;                // 64
		BSNonReentrantSpinLock                           clearRenderPassesLock;  // 68
	};
	static_assert(sizeof(BSShaderProperty) == 0x70);

	class __declspec(novtable) BSLightingShaderProperty :
		public BSShaderProperty  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderProperty };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSLightingShaderProperty };

		// members
		NiColorA                          projectedUVParams;           // 70
		NiColorA                          projectedUVColor;            // 80
		BSShaderProperty::RenderPassArray depthMapRenderPassListA[3];  // 90
		BSRenderPass*                     depthRenderPass;             // A8
		BSShaderProperty::RenderPassArray forwardPassList;             // B0
		NiColor*                          emitColor;                   // B8
		BSFixedString                     rootName;                    // C0
		float                             emitColorScale;              // C8
		float                             forcedDarkness;              // CC
		float                             specularLODFade;             // D0
		float                             envmapLODFade;               // D4
		std::uint32_t                     baseTechniqueID;             // D8
		std::uint32_t                     clearCommandBufferCount;     // DC
		std::uint16_t                     debugTintIndex;              // E0
		std::uint32_t                     stencilRef;                  // E4
	};
	static_assert(sizeof(BSLightingShaderProperty) == 0xE8);
}
