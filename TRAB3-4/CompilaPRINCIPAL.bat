@ECHO  OFF
REM  Compila todos os exemplos simples 
gmake /cPRINCIPAL /pgmake

pushd  .

del *.err

del *.obj
nmake /FPRINCIPAL.make 

copy  *.err  tudo.err

notepad tudo.err

popd
