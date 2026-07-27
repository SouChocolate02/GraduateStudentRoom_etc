/--自前で実装した自然数-/
inductive MyNat where
  /--ゼロ-/
  | zero
  /--後者関数(nに対してn+1を返す関数)-/
  | succ(n: MyNat)

  #check MyNat.zero
  #check MyNat.succ

  #check MyNat.succ .zero


/--自前で定義した1-/
def MyNat.one:= MyNat.succ .zero

/--自前で定義した2-/
def MyNat.two:= MyNat.succ .one

/--MyNat同士の足し算-/
def MyNat.add(m n : MyNat) : MyNat :=
  match n with
  | .zero => m
  | .succ n=> succ(add m n)
