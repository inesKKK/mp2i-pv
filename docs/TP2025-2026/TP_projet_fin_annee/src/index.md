{% assign doclist = site.pages | where: "url", "/mp2i-pv/TP2025-2026/TP_projet_fin_annee/src/" | sort: 'url' %}
<ul>
  {% for doc in doclist %}
      <li><a href="{{ site.baseurl }}{{ doc.url }}">{{ doc.url | remove: "/mp2i-pv/TP2025-2026/TP_projet_fin_annee/src/" }}</a></li>
  {% endfor %}
</ul>
