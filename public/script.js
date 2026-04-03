document.getElementById('matchForm').addEventListener('submit', async function(e) {
    e.preventDefault();

    const name = document.getElementById('name').value.trim();
    const blood = document.getElementById('blood').value;
    const location = document.getElementById('location').value.trim();
    const urgency = parseInt(document.getElementById('urgency').value, 10);

    const resultBox = document.getElementById('result');
    resultBox.style.display = 'none';
    resultBox.className = 'result-box';
    resultBox.textContent = '';

    try {
        const response = await fetch('/find-donor', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ name, blood, location, urgency })
        });

        const data = await response.json();
        resultBox.style.display = 'block';

        if (response.ok) {
            resultBox.classList.add('success');
            resultBox.textContent = data.result || 'Donor matched successfully.';
        } else {
            resultBox.classList.add('error');
            resultBox.textContent = 'Error:\n' + (data.error || 'Unknown error');
        }
    } catch (err) {
        resultBox.style.display = 'block';
        resultBox.classList.add('error');
        resultBox.textContent = 'Error:\n' + err.message;
    }
});