#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
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
		class Array;
		class Object;
		class Struct;
		class TypeInfo;
		class Variable;

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		template <class T>
		[[nodiscard]] BSTSmartPointer<Object> get(const Variable& a_var) requires(std::same_as<T, Object>);
		template <class T>
		[[nodiscard]] BSFixedString get(const Variable& a_var) requires(std::same_as<T, BSFixedString>);
		template <class T>
		[[nodiscard]] std::uint32_t get(const Variable& a_var) requires(std::same_as<T, std::uint32_t>);
		template <class T>
		[[nodiscard]] std::int32_t get(const Variable& a_var) requires(std::same_as<T, std::int32_t>);
		template <class T>
		[[nodiscard]] float get(const Variable& a_var) requires(std::same_as<T, float>);
		template <class T>
		[[nodiscard]] bool get(const Variable& a_var) requires(std::same_as<T, bool>);
		template <class T>
		[[nodiscard]] stl::observer<Variable*> get(const Variable& a_var) requires(std::same_as<T, Variable>);
		template <class T>
		[[nodiscard]] BSTSmartPointer<Struct> get(const Variable& a_var) requires(std::same_as<T, Struct>);
		template <class T>
		[[nodiscard]] BSTSmartPointer<Array> get(const Variable& a_var) requires(std::same_as<T, Array>);

		class Variable
		{
		public:
			Variable() noexcept = default;
			Variable(const Variable& a_rhs) { copy(a_rhs); }
			Variable(Variable&&) noexcept = default;

			~Variable() { reset(); }

			Variable& operator=(const Variable& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					reset();
					copy(a_rhs);
				}
				return *this;
			}

			Variable& operator=(Variable&&) noexcept = default;

			Variable& operator=(std::nullptr_t)
			{
				reset();
				assert(is<std::nullptr_t>());
				return *this;
			}

			Variable& operator=(BSTSmartPointer<Object> a_object);

			Variable& operator=(BSFixedString a_string)
			{
				reset();
				value.s = std::move(a_string);
				varType = RawType::kString;

				assert(is<BSFixedString>());
				return *this;
			}

			Variable& operator=(std::uint32_t a_unsigned)
			{
				reset();
				value.u = a_unsigned;
				varType = RawType::kInt;

				assert(is<std::uint32_t>());
				return *this;
			}

			Variable& operator=(std::int32_t a_signed)
			{
				reset();
				value.i = a_signed;
				varType = RawType::kInt;

				assert(is<std::int32_t>());
				return *this;
			}

			Variable& operator=(float a_float)
			{
				reset();
				value.f = a_float;
				varType = RawType::kFloat;

				assert(is<float>());
				return *this;
			}

			Variable& operator=(bool a_boolean)
			{
				reset();
				value.b = a_boolean;
				varType = RawType::kBool;

				assert(is<bool>());
				return *this;
			}

			Variable& operator=(stl::owner<Variable*> a_variable)
			{
				assert(a_variable != nullptr);
				assert(a_variable->varType.GetRawType() != RawType::kVar);

				reset();
				value.v = a_variable;
				varType = RawType::kVar;
				return *this;
			}

			Variable& operator=(BSTSmartPointer<Struct> a_struct);
			Variable& operator=(BSTSmartPointer<Array> a_array);

			F4_HEAP_REDEFINE_NEW(Variable);

			template <class T>
			[[nodiscard]] friend BSTSmartPointer<Object> get(const Variable& a_var)  //
				requires(std::same_as<T, Object>)
			{
				assert(a_var.is<Object>());
				return a_var.value.o;
			}

			template <class T>
			[[nodiscard]] friend BSFixedString get(const Variable& a_var)  //
				requires(std::same_as<T, BSFixedString>)
			{
				assert(a_var.is<BSFixedString>());
				return a_var.value.s;
			}

			template <class T>
			[[nodiscard]] friend std::uint32_t get(const Variable& a_var)  //
				requires(std::same_as<T, std::uint32_t>)
			{
				assert(a_var.is<std::uint32_t>());
				return a_var.value.u;
			}

			template <class T>
			[[nodiscard]] friend std::int32_t get(const Variable& a_var)  //
				requires(std::same_as<T, std::int32_t>)
			{
				assert(a_var.is<std::int32_t>());
				return a_var.value.i;
			}

			template <class T>
			[[nodiscard]] friend float get(const Variable& a_var)  //
				requires(std::same_as<T, float>)
			{
				assert(a_var.is<float>());
				return a_var.value.f;
			}

			template <class T>
			[[nodiscard]] friend bool get(const Variable& a_var)  //
				requires(std::same_as<T, bool>)
			{
				assert(a_var.is<bool>());
				return a_var.value.b;
			}

			template <class T>
			[[nodiscard]] friend stl::observer<Variable*> get(const Variable& a_var)  //
				requires(std::same_as<T, Variable>)
			{
				assert(a_var.is<Variable>());
				return a_var.value.v;
			}

			template <class T>
			[[nodiscard]] friend BSTSmartPointer<Struct> get(const Variable& a_var)  //
				requires(std::same_as<T, Struct>)
			{
				assert(a_var.is<Struct>());
				return a_var.value.t;
			}

			template <class T>
			[[nodiscard]] friend BSTSmartPointer<Array> get(const Variable& a_var)  //
				requires(std::same_as<T, Array>)
			{
				assert(a_var.is<Array>());
				return a_var.value.a;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, std::nullptr_t>)
			{
				return varType.GetRawType() == RawType::kNone;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Object>)
			{
				return varType.GetRawType() == RawType::kObject;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, BSFixedString>)
			{
				return varType.GetRawType() == RawType::kString;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, std::uint32_t> ||
						 std::same_as<T, std::int32_t>)
			{
				return varType.GetRawType() == RawType::kInt;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, float>)
			{
				return varType.GetRawType() == RawType::kFloat;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, bool>)
			{
				return varType.GetRawType() == RawType::kBool;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Variable>)
			{
				return varType.GetRawType() == RawType::kVar;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Struct>)
			{
				return varType.GetRawType() == RawType::kStruct;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Array>)
			{
				return varType.IsArray();
			}

			TypeInfo GetType() const
			{
				return varType;
			}

			void reset();

		private:
			using RawType = TypeInfo::RawType;

			void copy(const Variable& a_rhs);

			// members
			TypeInfo varType;  // 00
			union V
			{
				// NOLINTNEXTLINE(modernize-use-equals-default)
				V() :
					v(nullptr)
				{}

				V(V&& a_rhs)
				noexcept :
					v(std::exchange(a_rhs.v, nullptr))
				{}

				~V() {}  // NOLINT(modernize-use-equals-default)

				V& operator=(V&& a_rhs) noexcept
				{
					if (this != std::addressof(a_rhs)) {
						v = std::exchange(a_rhs.v, nullptr);
					}
					return *this;
				}

				BSTSmartPointer<Object> o;
				BSFixedString s;
				std::uint32_t u;
				std::int32_t i;
				float f;
				bool b;
				stl::owner<Variable*> v;
				BSTSmartPointer<Struct> t;
				BSTSmartPointer<Array> a;
			} value;  // 08
		};
		static_assert(sizeof(Variable) == 0x10);
	}
}
