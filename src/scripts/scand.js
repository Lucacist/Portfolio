function scandigital() {
  var cardplus = document.querySelector(".card_parent1");
  const body = document.body;

  if (cardplus.style.display === "none") {
    cardplus.style.display = "flex";
    body.classList.add("no-scroll"); // Désactive le défilement
  } else {
    cardplus.style.display = "none";
    body.classList.remove("no-scroll"); // Réactive le défilement
  }
}
