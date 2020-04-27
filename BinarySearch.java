import java.util.*;

class BinarySearch {

    // 5,8,9,20,30,40,45,50,55,64,78,90,95
    // 0 1 2 3  4  5  6  7  8  9  10 11 12
    public static void main(String[] args) {

        int[] arr = {5, 8, 9, 20, 30, 40, 45, 50, 55, 64, 78, 90, 95};
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number to be search in -> " + Arrays.toString(arr));
        int search = sc.nextInt();
        Map<Integer, Integer> map = binarySearchWithComments(arr, null, 0, arr.length, search);
        Integer ss = map.get(search);
        if (ss != null) {
            System.out.println("Value found = " + search + " , at index = " + ss);
        } else {
            System.out.println("Not found, but can be placed at -> " + map.get(-1));
        }
    }

    public static Map<Integer, Integer> binarySearchNoComments(int[] arr, int low, int high, int search) {
        if (high < low) {
            return Map.of(-1, low);
        }
        int midIndex = (low + high) / 2;
        int midNumber = arr[midIndex];
        if (midNumber == search) {
            return Map.of(midNumber, midIndex);
        } else if (search < midNumber) {
            return binarySearchNoComments(arr, low, midIndex - 1, search);
        } else {
            return binarySearchNoComments(arr, midIndex + 1, high, search);
        }
    }

    public static Map<Integer, Integer> binarySearchWithComments(int[] arr, List<Integer> list, int low, int high, int search) {
        if (high < low) {
            System.out.println("invalid  -> " + low + " - " + high);
            return Map.of(-1, low);
        }
        int midIndex = (low + high) / 2;
        int midNumber = getNumberAtIndex(arr, list, midIndex);
        if (midNumber == search) {
            return Map.of(midNumber, midIndex);
        } else if (search < midNumber) {
            System.out.println("Middle number -> " + midIndex+ "("+getNumberAtIndex(arr, list, midIndex)+")");
            System.out.println("Lower Searching in -> " + low + "(" + getNumberAtIndex(arr, list, low) + ")"+" - " + (midIndex - 1) + "(" + getNumberAtIndex(arr, list, midIndex - 1) + ")\n");
            return binarySearchWithComments(arr, list, low, midIndex - 1, search);
        } else {
            System.out.println("Middle number -> " + midIndex+ "("+getNumberAtIndex(arr, list, midIndex)+")");
            int tempHigh = (list != null && list.size() != high) || (arr != null && arr.length != high) ? high : high - 1;
            System.out.println("Higher Searching in -> " + (midIndex + 1) + "(" + getNumberAtIndex(arr, list, midIndex + 1) + ")" +" - " + tempHigh + "(" +
                    getNumberAtIndex(arr, list, tempHigh) + ")\n");
            return binarySearchWithComments(arr, list, midIndex + 1, high, search);
        }
    }

    private static int getNumberAtIndex(int[] arr, List<Integer> list, int index) {
        return list != null ? list.get(index) : arr[index];
    }
}
