function authen() {
  var cardplus = document.querySelector(".card_parent5");

  // Vérifier l'état actuel de l'affichage
  if (cardplus.style.display === "none") {
    // Si actuellement sur 'none', changer à 'flex'
    cardplus.style.display = "flex";
  } else {
    // Sinon, changer à 'none'
    cardplus.style.display = "none";
  }
}
