from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout
from os.path import join


class animaX(ConanFile):
    name = "animaX"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"
    exports_sources = "src/*"

    def requirements(self):
        self.requires("glad/0.1.36")
        self.requires("opengl/system")
        self.requires("glfw/3.4")
        self.requires("glm/cci.20230113")

    def configure(self):
        if self.settings.os == 'Linux':
            self.options['glad'].shared=False
            self.options['glad'].fPIC=True
            self.options['glad'].no_loader=False
            self.options['glad'].spec='gl'
            self.options['glad'].gl_profile='compatibility'
            self.options['glad'].gl_version='3.3'

    def layout(self):
        cmake_layout(self)
        self.folders.root = "."
        self.folders.source = "src"
        build_type = str(self.settings.build_type)
        self.folders.build = join("build", format(build_type))
        self.folders.generators = join(self.folders.build, "conan")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        CMake(self).configure()

    def build(self):
        CMake(self).build()

    def imports(self):
        self.copy("*.so*", src="lib", dst="bin")
        self.copy("*.dll", dst="bin", src="bin")

    def package(self):
        cmake = CMake(self)
        cmake.install()
