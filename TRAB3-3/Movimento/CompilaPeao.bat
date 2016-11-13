@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err

del *.obj
nmake /Fpeao.make 

copy  *.err  tudo.err

notepad tudo.err

popd
