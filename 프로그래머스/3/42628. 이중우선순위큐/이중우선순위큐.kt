import java.util.*

class Solution {
    fun solution(operations: Array<String>): IntArray {
    val treeMap = TreeMap<Int, Int>()

    operations.forEach {
        val (op, arg) = it.split(' ')
        if (op == "I") {
            treeMap[arg.toInt()] = treeMap.getOrDefault(arg.toInt(), 0) + 1;
        } else if (op == "D" && arg == "1") {
            if (treeMap.isEmpty()) return@forEach
            treeMap[treeMap.lastKey()] = treeMap.getOrDefault(treeMap.lastKey(), 0) - 1
            if (treeMap[treeMap.lastKey()] == 0) treeMap.remove(treeMap.lastKey())
        } else if (op == "D" && arg == "-1") {
            if (treeMap.isEmpty()) return@forEach
            treeMap[treeMap.firstKey()] = treeMap.getOrDefault(treeMap.firstKey(), 0) - 1
            if (treeMap[treeMap.firstKey()] == 0) treeMap.remove(treeMap.firstKey())
        }
    }

    if (treeMap.isEmpty()) return intArrayOf(0, 0)
    return intArrayOf(treeMap.lastKey().toInt(), treeMap.firstKey().toInt())
}
}