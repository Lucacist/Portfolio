function scandigital() {
  var cardplus = document.querySelector(".card_parent1");

  if (cardplus.style.display === "none") {
    cardplus.style.display = "flex";
  } else {
    cardplus.style.display = "none";
  }
}
