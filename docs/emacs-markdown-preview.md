# Emacs Markdown browser preview

The lesson diagrams use Mermaid. Pandoc converts Markdown to HTML; Mermaid then
draws the boxes and arrows in the browser. Internet access loads the Mermaid library.

In `~/.emacs.d/init.el`, use this in place of the existing Markdown preview settings.
Keep your other Markdown key bindings and file associations.

```elisp
(setq markdown-command '("pandoc" "--from=gfm" "--to=html5")
      markdown-command-needs-filename nil)

(with-eval-after-load 'markdown-mode
  (setq markdown-xhtml-header-content
        "<style>
pre { background: #172b4d; color: #f5f8ff; padding: 20px;
      border-radius: 10px; overflow-x: auto; }
pre.bash, pre.sh { background: #103d33; color: #e1fff1; }
pre.mermaid { background: #eff8ff; color: #17354a; }
</style>
<script type=\"module\">
import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';
mermaid.initialize({ startOnLoad: false });
const diagrams = document.querySelectorAll('pre.mermaid, pre:has(code.language-mermaid)');
for (const diagram of diagrams) {
  const source = diagram.textContent;
  diagram.replaceChildren(document.createTextNode(source));
  diagram.classList.add('mermaid');
}
await mermaid.run({ nodes: diagrams });
</script>"))
```

Restart Emacs, open a lesson, and run `M-x markdown-preview` to regenerate the page.
Reloading an older browser page alone does not regenerate it.

Do not add `--standalone`: markdown-mode must add its custom HTML header.
Pandoc wraps diagrams in `<pre><code>…</code></pre>`; the setup removes the inner
HTML wrapper before asking Mermaid to parse the text. Passing that wrapper caused
the earlier “Syntax error in text”.

If the corrected configuration is already installed, no additional patch is needed.
The old patches were specific to the earlier config and should not be reapplied.
