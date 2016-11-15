@ECHO  OFF
REM  Compila todos os exemplos simples 
gmake /cMainJOGO /pgmake

pushd  .

del *.err

del *.obj
nmake /FMainJOGO.make 

copy  *.err  tudo.err

notepad tudo.err

popd
