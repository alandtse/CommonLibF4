#pragma once

#include "RE/Bethesda/BSGraphics.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiProperty.h"

namespace RE
{
	class BSCombinedTriShape;
	class BSGeometrySegmentData;
	class BSMergeInstancedTriShape;
	class BSMultiIndexTriShape;

	namespace BSGraphics
	{
		struct IndexBuffer;
	}

	namespace BSSkin
	{
		class Instance;
	}

	class __declspec(novtable) BSGeometry :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometry };
		static constexpr auto VTABLE{ VTABLE::BSGeometry };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometry };

		BSGeometry();
		virtual ~BSGeometry();  // NOLINT(modernize-use-override) 00

		// add
		void UpdatePropertyControllers(NiUpdateData& a_data)  // 3A
		{
			REL::RelocateVirtual<decltype(&BSGeometry::UpdatePropertyControllers)>(0x3A, 0x3D, this, a_data);
		}

		BSGeometrySegmentData* GetSegmentData()  // 3B
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::GetSegmentData)>(0x3B, 0x3E, this);
		}

		void SetSegmentData(BSGeometrySegmentData* a_data)  // 3C
		{
			REL::RelocateVirtual<decltype(&BSGeometry::SetSegmentData)>(0x3C, 0x3F, this, a_data);
		}

		BSGraphics::IndexBuffer* GetCustomIndexBuffer()  // 3D
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::GetCustomIndexBuffer)>(0x3D, 0x40, this);
		}

		BSCombinedTriShape* IsBSCombinedTriShape()  // 3E
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::IsBSCombinedTriShape)>(0x3E, 0x41, this);
		}

		BSMergeInstancedTriShape* IsBSMergeInstancedTriShape()  // 3F
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::IsBSMergeInstancedTriShape)>(0x3F, 0x42, this);
		}

		BSMultiIndexTriShape* IsMultiIndexTriShape()  // 40
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::IsMultiIndexTriShape)>(0x40, 0x43, this);
		}

		std::uint32_t GetRenderableTris(std::uint32_t a_LODMode)  // 41
		{
			return REL::RelocateVirtual<decltype(&BSGeometry::GetRenderableTris)>(0x41, 0x44, this, a_LODMode);
		}

		// members
		NiBound                     modelBound;     // 120
		NiPointer<NiProperty>       properties[2];  // 130
		NiPointer<BSSkin::Instance> skinInstance;   // 140
		void*                       rendererData;   // 148
		BSGraphics::VertexDesc      vertexDesc;     // 150
		std::uint8_t                type;           // 158
		bool                        registered;     // 159
	};
	static_assert(sizeof(BSGeometry) == 0x160);

	class __declspec(novtable) BSTriShape :
		public BSGeometry  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTriShape };
		static constexpr auto VTABLE{ VTABLE::BSTriShape };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTriShape };

		BSTriShape();
		~BSTriShape() override;  // 00

		// override (BSGeometry)
		const NiRTTI* GetRTTI() const override  // 02
		{
			static REL::Relocation<const NiRTTI*> rtti{ BSTriShape::Ni_RTTI };
			return rtti.get();
		}

		BSTriShape* IsTriShape() override { return this; }  // 0A

		// members
		std::uint32_t numTriangles;  // 160
		std::uint16_t numVertices;   // 164
	};
	static_assert(sizeof(BSTriShape) == 0x170);
}
