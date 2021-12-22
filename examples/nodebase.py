# ----------------------------------------------------------------------------
# This is a WIP example of the node classes adjusted to use gsrenderer
# ----------------------------------------------------------------------------

# I think gsrenderer should be used in this base class rather than directly
# unless we swap the way things currenty work. Currently, the node classes
# defined in the ``nodes`` dir are the toplevel class that acts as the 
# controller.
#
# gsnodegraph expects a certain API of methods such as the Draw(dc) method
# and they need to be toplevel. This may not be possible if we use gsrenderer
# directly in the node definitions.

import gsrenderer



class NodeView(gsnodegraph.Node):
    def __init__(self, nodegraph, _id):
        gsrenderer.Node.__init__(self, nodegraph, _id)


class Node(NodeView):
    def __init__(self, nodegraph, _id):
        NodeView.Node.__init__(self, nodegraph, _id)
        