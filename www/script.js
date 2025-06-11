document.addEventListener('DOMContentLoaded', function () {
    const loadBtn = document.getElementById('load_settings');
    const saveBtn = document.getElementById('save_settings');
    const statusDiv = document.getElementById('status');

    // Load current settings
    loadBtn.addEventListener('click', loadSettings);
    saveBtn.addEventListener('click', saveSettings);

    // Load settings on page load
    loadSettings();

    function showStatus(message, isError = false) {
        statusDiv.textContent = message;
        statusDiv.className = 'status ' + (isError ? 'error' : 'success');
        setTimeout(() => {
            statusDiv.textContent = '';
            statusDiv.className = 'status';
        }, 3000);
    }

    async function loadSettings() {
        try {
            const response = await fetch('/api/globals');
            if (!response.ok) throw new Error('Failed to load settings');

            const data = await response.json();

            // Populate form fields
            document.getElementById('location_name').value = data.location_name || '';
            document.getElementById('latitude').value = data.location_latitude || 37.1;
            document.getElementById('longitude').value = data.location_longitude || -8.0;
            document.getElementById('automation_mode').value = data.automation_mode || 0;
            document.getElementById('sunset_duration').value = data.sunset_duration_hours || 2;
            document.getElementById('sunrise_duration').value = data.sunrise_duration_hours || 1;
            document.getElementById('until_time_hour').value = data.sunset_until_time_hour || 23;
            document.getElementById('until_time_minute').value = data.sunset_until_time_minute || 0;
            document.getElementById('from_time_hour').value = data.sunrise_from_time_hour || 6;
            document.getElementById('from_time_minute').value = data.sunrise_from_time_minute || 0;
            document.getElementById('manual_duration').value = data.manual_duration_hours || 4;
            document.getElementById('winter_mode').checked = data.sw3_winter_mode || false;

            showStatus('Settings loaded successfully');
        } catch (error) {
            showStatus('Failed to load settings: ' + error.message, true);
        }
    }

    async function saveSettings() {
        try {
            const settings = {
                location_name: document.getElementById('location_name').value,
                location_latitude: parseFloat(document.getElementById('latitude').value),
                location_longitude: parseFloat(document.getElementById('longitude').value),
                automation_mode: parseInt(document.getElementById('automation_mode').value),
                sunset_duration_hours: parseInt(document.getElementById('sunset_duration').value),
                sunrise_duration_hours: parseInt(document.getElementById('sunrise_duration').value),
                sunset_until_time_hour: parseInt(document.getElementById('until_time_hour').value),
                sunset_until_time_minute: parseInt(document.getElementById('until_time_minute').value),
                sunrise_from_time_hour: parseInt(document.getElementById('from_time_hour').value),
                sunrise_from_time_minute: parseInt(document.getElementById('from_time_minute').value),
                manual_duration_hours: parseInt(document.getElementById('manual_duration').value),
                sw3_winter_mode: document.getElementById('winter_mode').checked
            };

            const response = await fetch('/api/globals', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify(settings)
            });

            if (!response.ok) throw new Error('Failed to save settings');

            const result = await response.json();
            showStatus('Settings saved successfully! Device will update automatically.');

        } catch (error) {
            showStatus('Failed to save settings: ' + error.message, true);
        }
    }
});
