from procure import GitSolution

"""
[submodule "libs/faust"]
	url = https://github.com/grame-cncm/faust
[submodule "libs/fmt"]
	url = https://github.com/fmtlib/fmt
[submodule "libs/glad"]
	url = https://github.com/Dav1dde/glad
[submodule "libs/glfw"]
	url = https://github.com/glfw/glfw
[submodule "libs/imgui"]
	url = https://github.com/ocornut/imgui
[submodule "libs/imknobs"]
	url = https://github.com/altschuler/imgui-knobs
[submodule "libs/imnodes"]
	url = https://github.com/Nelarius/imnodes
[submodule "libs/implot"]
	url = https://github.com/epezent/implot
[submodule "libs/rtaudio"]
	url = https://github.com/thestk/rtaudio
[submodule "libs/rtmidi"]
	url = https://github.com/thestk/rtmidi
[submodule "libs/vst3sdk"]
	url = https://github.com/steinbergmedia/vst3sdk
[submodule "libs/xtensor"]
	url = https://github.com/xtensor-stack/xtensor
[submodule "libs/xtl"]
	url = https://github.com/xtensor-stack/xtl
"""


class Faust(GitSolution):
    path = "depot/faust"
    url = "https://github.com/grame-cncm/faust"


class Fmt(GitSolution):
    path = "depot/fmt"
    url = "https://github.com/fmtlib/fmt"


class Glad(GitSolution):
    path = "depot/glad"
    url = "https://github.com/Dav1dde/glad"


class Glfw(GitSolution):
    path = "depot/glfw"
    url = "https://github.com/glfw/glfw"


class ImGui(GitSolution):
    path = "depot/imgui"
    url = "https://github.com/ocornut/imgui"


class ImGuiKnobs(GitSolution):
    path = "depot/imknobs"
    url = "https://github.com/altschuler/imgui-knobs"


class ImNodes(GitSolution):
    path = "depot/imnodes"
    url = "https://github.com/Nelarius/imnodes"


class ImPlot(GitSolution):
    path = "depot/implot"
    url = "https://github.com/epezent/implot"


class RtAudio(GitSolution):
    path = "depot/rtaudio"
    url = "https://github.com/thestk/rtaudio"


class RtMidi(GitSolution):
    path = "depot/rtmidi"
    url = "https://github.com/thestk/rtmidi"


class VST3SDK(GitSolution):
    path = "depot/vst3sdk"
    url = "https://github.com/steinbergmedia/vst3sdk"


class Xtensor(GitSolution):
    path = "depot/xtensor"
    url = "https://github.com/xtensor-stack/xtensor"


class Xtl(GitSolution):
    path = "depot/xtl"
    url = "https://github.com/xtensor-stack/xtl"


solutions = [
    Faust,
    Fmt,
    Glad,
    Glfw,
    ImGui,
    ImGuiKnobs,
    ImNodes,
    ImPlot,
    RtAudio,
    RtMidi,
    VST3SDK,
    Xtensor,
    Xtl,
]
