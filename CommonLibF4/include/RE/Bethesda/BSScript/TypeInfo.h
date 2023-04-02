#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class IComplexType;
		class ObjectTypeInfo;
		class StructTypeInfo;

		class TypeInfo
		{
		public:
			enum class RawType : std::uint32_t
			{
				kNone,
				kObject,
				kString,
				kInt,
				kFloat,
				kBool,
				kVar,
				kStruct,

				kArrayStart = 10,
				kArrayObject,
				kArrayString,
				kArrayInt,
				kArrayFloat,
				kArrayBool,
				kArrayVar,
				kArrayStruct,
				kArrayEnd
			};

			TypeInfo() noexcept = default;
			TypeInfo(const TypeInfo& a_rhs) noexcept { data.complexTypeInfo = a_rhs.data.complexTypeInfo; }
			TypeInfo(TypeInfo&& a_rhs) noexcept { data.complexTypeInfo = std::exchange(a_rhs.data.complexTypeInfo, nullptr); }
			TypeInfo(RawType a_type) noexcept { data.rawType = a_type; }
			TypeInfo(IComplexType* a_type) noexcept { data.complexTypeInfo = a_type; }

			TypeInfo& operator=(const TypeInfo& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data.complexTypeInfo = a_rhs.data.complexTypeInfo;
				}
				return *this;
			}

			TypeInfo& operator=(TypeInfo&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data.complexTypeInfo = std::exchange(a_rhs.data.complexTypeInfo, nullptr);
				}
				return *this;
			}

			TypeInfo& operator=(RawType a_type) noexcept
			{
				data.rawType = a_type;
				return *this;
			}

			TypeInfo& operator=(IComplexType* a_type) noexcept
			{
				data.complexTypeInfo = a_type;
				return *this;
			}

			[[nodiscard]] RawType GetRawType() const;

			[[nodiscard]] bool IsArray() const noexcept
			{
				if (IsComplex()) {
					return data.rawType.all(static_cast<RawType>(1u));
				} else {
					return RawType::kArrayStart < data.rawType && data.rawType < RawType::kArrayEnd;
				}
			}

			[[nodiscard]] bool IsComplex() const noexcept { return data.rawType >= RawType::kArrayEnd; }

			[[nodiscard]] bool IsObjectArray() const noexcept
			{
				return GetRawType() == RawType::kArrayObject;
			}
			[[nodiscard]] bool IsStructArray() const noexcept
			{
				return GetRawType() == RawType::kArrayStruct;
			}
			[[nodiscard]] bool IsComplexTypeArray() const noexcept
			{
				return (IsComplex() && IsArray());
			}
			[[nodiscard]] bool IsObject() const { return GetRawType() == RawType::kObject; }
			[[nodiscard]] bool IsStruct() const { return GetRawType() == RawType::kStruct; }
			IComplexType* GetComplexType() const;
			StructTypeInfo* GetStructTypeInfo() const;
			ObjectTypeInfo* GetObjectTypeInfo() const;

			void SetArray(bool a_set) noexcept
			{
				if (IsComplex()) {
					if (a_set) {
						assert(!IsArray());
						data.rawType.set(static_cast<RawType>(1u));
					} else {
						assert(IsArray());
						data.rawType.reset(static_cast<RawType>(1u));
					}
				} else {
					if (a_set) {
						assert(!IsArray());
						data.rawType += RawType::kArrayStart;
					} else {
						assert(IsArray());
						data.rawType -= RawType::kArrayEnd;
					}
				}
			}

			// members
			union D
			{
				D()
				noexcept :
					complexTypeInfo(nullptr)
				{}

				~D() noexcept { complexTypeInfo = nullptr; }

				stl::enumeration<RawType, std::uintptr_t> rawType;
				IComplexType* complexTypeInfo;
			} data;  // 0
		};
		static_assert(sizeof(TypeInfo) == 0x8);
	}
}
