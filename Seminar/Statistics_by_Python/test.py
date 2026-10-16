# import numpy as np
# A = np.array([
#     [0, 1], 
#     [3, 4]
#     ])
# B = np.array([
#     [3, 2],
#     [4, 5]
#     ])
# print(A)
# print(B)
# product= A@B
# print(product)

# a=[1,2,3,4,5]
# print(a[1])

# %%time

# import numpy as np
# """
# A x = bを満たすxベクトルを linalg.solveを使って求める
# """
# # 行列Aの生成
# a1_lis = [1, 0, 0]
# a2_lis = [0, 2, 0]
# a3_lis = [0, 0, 4] 
# A_matrix=np.array([a1_lis, a2_lis, a3_lis])

# # b vector
# b = np.array([4,5,6]) # 行ベクトルとしてｂを生成し，それの転置行列として"列ベクトル”を生成する
# b_vec = b.T
# A_inv = np.linalg.inv(A_matrix)
# x_vec= A_inv@b_vec # xベクトルを計算する。行列の積に@演算子を使っている(参考)

# print(x_vec)

