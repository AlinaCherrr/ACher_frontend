const menubtn = document.querySelector(".menu-btn");
const navigation = document.querySelector(".navigation");
const title = document.querySelector('.navigation__title')
const header = document.querySelector('.header')

menubtn.addEventListener('click', () => {
    menubtn.classList.toggle('active');
    navigation.classList.toggle('active');
})

const btns = document.querySelectorAll('.home__nav-btn');
const slides = document.querySelectorAll('.home__videoslide');
const contents = document.querySelectorAll('.home__content');

let sliderNav = function(manual){
    console.log(manual)
    btns.forEach(btn => {
    btn.classList.remove('active');
    })

    slides.forEach(slide => {
        slide.classList.remove('active');
    })

    contents.forEach(content => {
        content.classList.remove('active');
    })

    btns[manual].classList.add('active');
    slides[manual].classList.add('active');
    contents[manual].classList.add('active');

    if (manual != 0) {
        title.classList.remove('hide')
        header.classList.add('header_wide')
    } else {
        title.classList.add('hide')
        header.classList.remove('header_wide')
    }
}

btns.forEach((btn, i) => {
    btn.addEventListener('click', () => { sliderNav(i) });
})