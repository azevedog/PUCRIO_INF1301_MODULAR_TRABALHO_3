@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err
del TesteJogo.exe

del *.obj
nmake /FTesteJogo.make 

copy  *.err  tudo.err

notepad tudo.err

popd
