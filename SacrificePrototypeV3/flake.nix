{
  description = "A simple Lua C++ integration project";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default = let
      pkgs = import nixpkgs {
        system = "x86_64-linux";
        config.allowUnfree = true;
      };
    in
      pkgs.mkShell {
        buildInputs = with pkgs; [
          gcc
          lua
          gtest
        ];
      };
  };
}

