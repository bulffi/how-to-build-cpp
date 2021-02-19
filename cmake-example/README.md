# CMake

I found out that we can use **CMake** together with **vcpkg**.

Still, how to incorporate .proto file compilation into the over all flow
is still not very perfect, I'll looking for this further.

## Local Dev

```shell script
git submodule add https://github.com/microsoft/vcpkg.git vcpkg
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install gtest grpc
```
 Then you get everything!
 
 ## Container Dev
 
 I'm trying remote dev with Clion, it's kind of different from that of VS Code.
 In Clion, your files remain local instead of being in the remote dev env.
 
 You can try the shell script I wrote in `dev-docker.start.sh`
 
 In this case, the vcpkg will be in the container, you don't have to add a 
 submodule like before.