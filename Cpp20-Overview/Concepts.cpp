#include <type_traits>
#include <concepts>

// A concept is a set of constraints on template parameters evaluated at compile time.

namespace ConceptsCpp20
{
	struct Receipt
	{
		long ReceiptRef;
		long status;
	};

	struct Allocation
	{
		long AllocationRef;
		long status;
	};

	template <typename T>
	concept IsReceipt = std::is_same_v<T, Receipt>;

	template <typename T>
	requires IsReceipt<T>
	void Post(T)
	{}

	void foo()
	{
		Receipt receipt{};
		Allocation allocation{};

		Post(receipt);
		//Post(allocation); doesn't compile
	}

	//------------------------------------------

	struct Client
	{
		long ClientRef;
	};

	struct Agent
	{
		long AgentRef;
	};

	template <typename T>
	void PrintClientDocument(T) requires std::is_same_v<T, Client>
	{}

	void boo()
	{
		Client client{};
		Agent agent{};

		PrintClientDocument(client);
		//PrintClientDocument(agent); doesn't compile
	}

	//------------------------------------------

	struct Duck
	{
		void Swim() {}
		void Move() {}
		void Fly() {}
	};

	struct Dog
	{
		void Swim() {}
		void Move() {}
	};

	template <typename T>
	concept FlyingAmphibious = requires(T t)
	{
		t.Swim();
		t.Move();
		t.Fly();
	};

	template <typename T>
	void Go(const T& t) requires FlyingAmphibious<T>
	{}

	void doo()
	{
		Duck duck;
		Dog dog;

		Go(duck);
		//Go(dog); doesn't compile
	}

	//------------------------------------------

	struct NotCopyConstructible
	{
		NotCopyConstructible() = default;
		NotCopyConstructible(const NotCopyConstructible&) = delete;
	};

	struct CopyConstructible
	{
		CopyConstructible() = default;
		CopyConstructible(const CopyConstructible&) = default;
	};

	template <typename T>
	void hoo(T) requires std::copy_constructible<T>
	{}

	void goo()
	{
		hoo(CopyConstructible{});
		//hoo(NotCopyConstructible{}); doesn't compile
	}


}