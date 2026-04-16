// stack i heap

int main()
{
  // Stack:
  //

  // Heap:
  //

  int stack_x = 10;

  // Stack:
  //   stack_x

  {
    // Stack:
    //   stack_x
    //
    double stack_y = 20.0;

    // Stack:
    //   stack_x
    //   stack_y
  }

  // Stack:
  //   stack_x

  // Heap:
  //

  int* heap_x = new int;
  *heap_x = 10;

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_x

  {
    // Stack:
    //   stack_x
    //   heap_x

    // Heap:
    //   *heap_x

    double* heap_y = new double(20.0);

    // Stack:
    //   stack_x
    //   heap_x
    //   heap_y

    // Heap:
    //   *heap_x
    //   *heap_y
  }

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_x
  //   *heap_y

  delete heap_x;

  // Stack:
  //   stack_x
  //   heap_x

  // Heap:
  //   *heap_y
}

// Stack:
//

// Heap:
//   *heap_y
