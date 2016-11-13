@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err

del *.obj
nmake /Fbispo.make 

copy  *.err  tudo.err

notepad tudo.err

popd
