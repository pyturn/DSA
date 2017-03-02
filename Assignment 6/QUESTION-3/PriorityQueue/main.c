  #include <stdio.h>
  #include <stdlib.h>

  #define HEAPCOUNT 100

  int count = 0;

  /*
   * find the smallest among the left(data[pos])  and
   * right child(data[pos + 1]).  Check whether the smallest
   * among them is lesser than their parent.  If so, swap
   * parent and the node with smallest value.  Continue the
   * above processing from index "low" to "count"
   *         40
   *        /   \
   *       10   30
   *  10 is smaller tha 30. 10 is comapared with its parent
   *  and it is smaller(10 < 40).  So, swap parent and 10.
   *         10
   *       /    \
   *      40    30
   */
  void insertHeap(int *data, int low, int count) {
        int pos = (2 * low) + 1, current = data[low];
        while (pos <= count) {
                if (pos < count && data[pos] > data[pos + 1])
                        pos++;
                if (current <= data[pos])
                        break;
                else {
                        data[low] = data[pos];
                        low = pos;
                        pos = (2 * low) + 1;
                }
        }
        data[low] = current;
        return;
  }

  /*
   * To construct a heap we always consider the 
   * nodes which are present above the leaf.  Here,
   * nodes present after data[n/2 - 1] are leaf nodes
   * insertHeap() - used for restoring the heap
   * data - holds node values & n - node count
   */
  void buildHeap(int *data, int n) {
        int low;
        for (low = n/2 - 1; low >= 0; low--) {
                insertHeap(data, low, n-1);
        }
        return;
  }

  void buildUp(int *data, int index) {
        int val = data[index];
        /* if parent of the current node has value
         * greater than its child, then swap parent
         * and child nodes.  Traverse up the tree
         * until u hit a condition where parent node
         * is having lesser value than children
         */
        while (data[(index - 1) / 2] >= val) {
                data[index] = data[(index - 1) / 2];
                if (!index)
                        break;
                index = (index - 1) / 2;
        }
        data[index] = val;
        return;
  }

  /* adding new node to the binary heap */
  void addNode(int *data, int val, int n) {
        data[n] = val;
        buildUp(data, n);
        return;
  }

  /* delete a node from binary heap */
  void deleteNode(int *data, int n) {
        int val = data[0];
        data[0] = data[n];
        insertHeap(data, 0, n - 1);
        printf("%d is deleted from the heap\n", val);
        return;
  }

  /* replacing root node with value val */
  void replaceNode(int *data, int val, int n) {
        int i;
        data[0] =  val;
        for (i = n/2 - 1; i >= 0; i--)
                insertHeap(data, i, n - 1);
        return;
  }

  void display(int *data, int n) {
        int i;
        printf("\nData in Binary Heap:\n");
        for (i = 0; i <= n; i++) {
                printf("%d ", data[i]);
        }
        printf("\n\n");
  }

  int main() {
        int n, i, *data, temp, ch, val;
        data = (int *)malloc(sizeof(int) * HEAPCOUNT);
        printf("Enter the no of elements(1-80):");
        scanf("%d", &n);

        if (n < 1 || n > 80) {
                printf("Threshold Exceeded!!\n");
                return 0;
        }

        for (i = 0; i < n; i++) {
                printf("Input %d:", i + 1);
                scanf("%d", &data[i]);
                count++;
        }

        buildHeap(data, n);
        while (n  < (HEAPCOUNT -1)) {
                printf("1. Add New Node\t2. Delete Node\n");
                printf("3. Replace Node\t4. Display Heap\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);

                switch(ch) {
                        case 1:
                                printf("Enter your input:");
                                scanf("%d", &val);
                                addNode(data, val, n);
                                n++;
                                break;
                        case 2:
                                deleteNode(data, n -1);
                                n--;
                                break;
                        case 3:
                                printf("Enter input value:");
                                scanf("%d", &val);
                                replaceNode(data, val, n);
                                break;
                        case 4:
                                display(data, n - 1);
                                break;
                        case 5:
                                goto sort;

                        default:
                                printf("Wrong Option!!\n");
                                break;
                }

        }
  sort:
        /* swap root and current last node, then perform
         * restore heap to get data in sorted order.  Basically,
         * we are performing insort operation.
         */
        for (i = n - 1; i > 0; i--) {
                temp = data[i];
                data[i] = data[0];
                data[0] = temp;
                insertHeap(data, 0, i - 1);
        }
        printf("Sorted Data:\n");
        for (i = 0; i < n; i++)
                printf("%d ", data[i]);
        printf("\n");
        return 0;
  }

