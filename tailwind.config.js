/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{html,js}", "./node_modules/flowbite/**/*.js"],
  theme: {
    extend: {
      colors:{
        primary: '#00ADB5',
        secondary: '#222831',
        tertiary: '#EEEEEE',
      },
      fontFamily: {
        righteous: ['Righteous'],
        poppins: ['Poppins', 'sans-serif'],
        timesnewroman: ['timesnewroman']
      },
      dropShadow: {
        'neon': '0 0px 15px rgba(0, 173, 181,0.50)',
      },
      boxShadow: {
        'neon': '0 0px 35px rgba(0, 173, 181,0.50)',
        'pressed': 'inset 12px 12px 24px #9c9c9c, inset -12px -12px 24px #9c9c9c',
      },
    },
  },
  plugins: [
    require('flowbite/plugin'), 
    require('flowbite-typography'),
  ],
}

