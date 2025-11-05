# Deletion Node Pada Binary Search Tree

<p style="text-align=justify">

pada <code>Binary Search Tree</code> ada beberapa aturan yaitu nilai node pada subtree kiri selalu lebih kecil
daripada nilai root,dan nilai node pada subtree kanan selalu lebih besar daripada nilai root.Pada operasi deletion terasa cukup menantang dikarenakan pada saat menghapus node kita harus mempertahankan aturan tersebut.

</p>

## Kasus pada operasi deletion

<p style="text-align=justify">

Untuk mempertahankan autran pada BST,maka dari itu ada 3 Kasus utama operasi deletion pada <code>Binary Search Tree </code>,yaitu:

</p>

### Kasus 1: Node adalah leaf

misal pada tree:

```math
    5
   / \
  3   6
     /
    4
```

ini adalah kasus paling mudah,misal kita ingin hapus node `4` maka dapat langsung hapus node tersebut dan set `parent` ke node tersebut `nullptr`.

### Kasus 2: Node punya 1 anak

Misal pada tree:

```math
    5
   /
  3
   \
    4
```

pada kasus ini kita melakukan relingking node,misal kita ingin hapus 3,maka
kita harus relingking parent dari 3 dengan child dari 3,lalu menghapus node tersebut

### Kasus 3: Node punya 2 anak

misal pada tree:

```math
        8
       / \
      3   10
     / \    \
    1   6    14
       / \
      4   7

```

misal kita ingin  hapus node 3,maka tidak cukup dengan relinking karena child node 3 akan kehilangan hubungan,maka dari itu harus diganti dengan nilai yang lain agar BST tetap valid.Ada 2 pilihan nilai pengganti yaitu: 

1.Inorder successor → node terkecil di subtree kanan
(nilai paling kecil setelah node yang dihapus)

2.Inorder predecessor → node terbesar di subtree kiri
(nilai paling besar sebelum node yang dihapus)