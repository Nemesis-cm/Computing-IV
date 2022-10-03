// Copyright 2021 Thomas Freeman

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "StringSound.hpp"

// takes input from string sound to make vector of samples
std::vector<sf::Int16> makeSamples(StringSound* gs);

// initializes said vector
void setupSoundBuffers(const std::vector<std::vector<sf::Int16>>& samples,
 std::vector<sf::SoundBuffer>* soundBuffers);

// initializes vector from sound buffers
void setupSounds(const std::vector<sf::SoundBuffer>& soundBuffers,
 std::vector<sf::Sound>* sounds);

// Display setup
int main(int argc, char* argv[]) {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    if (!image.loadFromFile("Keys.png")) {
        throw std::runtime_error("sf::Image: could not load Keys.png");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    sf::RenderWindow window(sf::VideoMode(image.getSize().x,
    image.getSize().y), "KS Guitar Sim");

    // keys used to play guitar
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/'";
    std::vector<std::vector<sf::Int16>> samples;
    std::vector<sf::SoundBuffer> soundBuffers;
    std::vector<sf::Sound> sounds;
    StringSound gs;
    // Frequency determines sound
    double freq;

    // sampes are created for each key
    for (int i = 0; i < static_cast<int>(keys.length()); i++) {
        freq = 440 * pow(2, (static_cast<double>(i) - 24) / 12);
        try {
            gs = StringSound(freq);
        }
        catch (std::invalid_argument err) {
            std::cerr << err.what() << std::endl;
        }
        samples.push_back(makeSamples(&gs));
    }

    setupSoundBuffers(samples, &soundBuffers);
    setupSounds(soundBuffers, &sounds);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Checks for pressed key, if pressed, plays given sound sample
            if (event.type == sf::Event::TextEntered) {
                char key = static_cast<char>(event.text.unicode);
                for (int i = 0; i < static_cast<int>(keys.length()); i++) {
                    if (key == keys[i]) {
                        sounds[i].play();
                    }
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

// includes the duration of pluck as int
std::vector<sf::Int16> makeSamples(StringSound* gs) {
    std::vector<sf::Int16> sampleStream;
    gs->pluck();
    int duration = 8;
    for (int i = 0; i < SAMPLE_RATE * duration; i++) {
        gs->tic();
        sampleStream.push_back(gs->sample());
    }
    return sampleStream;
}

// Exception for unloadble sound buffer
void setupSoundBuffers(const std::vector<std::vector<sf::Int16>>& samples,
 std::vector<sf::SoundBuffer>* soundBuffers) {
    sf::SoundBuffer buffer;
    for (int i = 0; i < static_cast<int>(samples.size()); i++) {
        if (!buffer.loadFromSamples(&(samples[i])[0], samples[i].size(), 2,
        SAMPLE_RATE)) {
            throw std::runtime_error("setupSoundBuffers(): could not load"
            " SoundBuffer");
        }
        soundBuffers->push_back(buffer);
    }
}

void setupSounds(const std::vector<sf::SoundBuffer>& soundBuffers,
 std::vector<sf::Sound>* sounds) {
     sf::Sound sound;
     for (int i = 0; i < static_cast<int>(soundBuffers.size()); i++) {
        sound.setBuffer(soundBuffers[i]);
        sounds->push_back(sound);
     }
}
