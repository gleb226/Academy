function startCountdown() {
    let totalSeconds = 60 * 60 * 60;

    function updateCountdown() {
        let hours = Math.floor(totalSeconds / 3600);
        let minutes = Math.floor((totalSeconds % 3600) / 60);
        let seconds = totalSeconds % 60;

        document.getElementById("hours").textContent = String(hours).padStart(2, '0');
        document.getElementById("minutes").textContent = String(minutes).padStart(2, '0');
        document.getElementById("seconds").textContent = String(seconds).padStart(2, '0');

        totalSeconds--;
        if (totalSeconds >= 0) {
            setTimeout(updateCountdown, 1000);
        }
    }

    updateCountdown();
}

startCountdown();