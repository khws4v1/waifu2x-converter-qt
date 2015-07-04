# waifu2x-converter-qt

waifu2x-converter-cppのGUIフロントエンド

## 動作環境
* Windows
* Mac OS X
* Linux

**waifu2x-converter-cppは自分で用意してください。**  
waifu2x-converter-cppベースのwaifu2xなら問題なく利用できます。

## 動作確認済waifu2x

### [waifu2x-converter-cpp](https://github.com/WL-Amigo/waifu2x-converter-cpp)
作者: amigo

MacとLinuxのバイナリは公開されていないので僕が[コンパイルするスクリプト](https://github.com/khws4v1/waifu2x-converter-cpp)を書きました。

### [waifu2x-converter-glsl](https://github.com/ueshita/waifu2x-converter-glsl)
作者: ueshita

MacとLinuxのバイナリは公開されていないので僕が[コンパイルするCMakeスクリプト](https://github.com/khws4v1/waifu2x-converter-glsl)を書きました。

### それ以外
大変申し訳無いのですが、CUDAとかAVX2とか言われてもそんなもの動くPC無いので、それらが無いと動かないwaifu2xに関しては動作確認なんかできっこないので頑張ってください。

## 使い方
### 初期設定
ツール->設定からwaifu2xのバイナリの場所を指定するだけで使えるようになります。

### トラブルシューティング
コマンドライン引数はwaifu2x-converter-cpp基準ですが、それと異なる場合は設定から細かく変えられるので弄ったら動くかもしれませんよ。

