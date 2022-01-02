# gsrenderer

An experimental C++ node evaluation engine and renderer for Gimel Studio.

**Disclaimer: this is still at the idea stage. Nothing actually works just yet.**

If you'd like to help with this (either with ideas or code), please let us know on the [Gimel Studio Discord](https://discord.gg/RqwbDrVDpK).

## Brief overview of what gsrenderer does

**Work in progress. Subject to change.**

There are three "global" renderer methods, ``gsrenderer.GetImage()``, ``gsrenderer.SetImage()`` and ``gsrenderer.RenderImage()``.

- ``gsrenderer.GetImage()`` gets the image (stored in C++).
- ``gsrenderer.RenderImage()`` starts the node evaluation process (rendering).
- The method ``gsrenderer.SetImage()`` sets the image and is mainly used in the Python API to send a modified image back to gsrenderer so that the modified image can be accessed using ``gsrenderer.GetImage()``.

The node evaluating process sets the output image which is what is accessed by ``gsrenderer.GetImage()``. To allow nodes to be written in Python, a base node class needs to be written that can be inherited from.

When the image stored in ``gsrenderer`` is changed, an event (e.g. ``EVT_RENDER_IMAGE_CHANGED``) is sent which can then be binded to a function to (e.g. ``self.Bind(EVT_RENDER_IMAGE_CHANGED, self.OnRenderImageChanged)``). The function can then call the required functions to refresh/update the viewport

- Add an empty method meant to be overridden in the Python subclass which acts as an update hook. Call this method when the image in ``gsrenderer`` is updated.
