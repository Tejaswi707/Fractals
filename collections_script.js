// Selecting necessary elements
const images = document.querySelectorAll('.image');
const previewBox = document.querySelector('.preview-box');
const previewImg = previewBox.querySelector('img');
const categoryTitle = previewBox.querySelector('.title p');
const closeIcon = previewBox.querySelector('.icon');
const shadow = document.querySelector('.shadow');

// Function to show preview box
images.forEach(image => {
  image.addEventListener('click', () => {
    const imgSrc = image.querySelector('img').src;
    const category = image.dataset.name;
    previewImg.src = imgSrc;
    categoryTitle.textContent = category;
    previewBox.style.display = 'block';
    shadow.style.display = 'block';
  });
});

// Function to hide preview box
closeIcon.addEventListener('click', () => {
  previewBox.style.display = 'none';
  shadow.style.display = 'none';
});
