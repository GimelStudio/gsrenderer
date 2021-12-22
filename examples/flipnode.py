# ----------------------------------------------------------------------------
# This is a WIP example of the flip node adjusted to use gsrenderer
# ----------------------------------------------------------------------------

# gsrenderer handles the backend
import gsrenderer  
# gimelstudio.api handles the frontend
from gimelstudio import api


try:
    import OpenImageIO as oiio
except ImportError:
    print("""OpenImageIO is required! Get the python wheel for Windows at:
     https://www.lfd.uci.edu/~gohlke/pythonlibs/#openimageio""")


class FlipNode(gsrenderer.Node):
    def __init__(self, nodegraph, _id):
        gsrenderer.Node.__init__(self, nodegraph, _id)

    @property
    def NodeMeta(self):
        meta_info = {
            "label": "Flip",
            "author": "Gimel Studio",
            "version": (0, 5, 0),
            "category": "TRANSFORM",
            "description": "Flips the orientation of the image.",
        }
        return meta_info

    def NodeInitProps(self):
        self.direction = api.ChoiceProp(
            idname="direction",
            default="Vertically",
            choices=["Vertically", "Horizontally", "Diagonally"],
            fpb_label="Orientation"
        )
        self.NodeAddProp(self.direction)

    def NodeInitParams(self):
        image = gsrenderer.ImageParam("image", "Image")

        self.NodeAddParam(image)

    def MutedNodeEvaluation(self, eval_info):
        return self.EvalMutedNode(eval_info)

    def NodeEvaluation(self, eval_info):
        flip_direction = self.EvalProperty(eval_info, "direction")
        
        input_image = self.EvalParameter(eval_info, "image")

        if flip_direction == "Vertically":
            output_image = oiio.ImageBufAlgo.flip(input_image)
        elif flip_direction == "Horizontally":
            output_image = oiio.ImageBufAlgo.flop(input_image)
        elif flip_direction == "Diagonally":
            output_image = oiio.ImageBufAlgo.transpose(input_image)

        gsrenderer.SetImage(output_image)
        self.NodeUpdateThumb(output_image)


gsrenderer.RegisterNode(FlipNode, "corenode_flip")
