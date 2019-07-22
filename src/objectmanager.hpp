#ifndef OBJECTMANAGER_HPP_
#define OBJECTMANAGER_HPP_
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "collision.hpp"
#include "interaction.hpp"
class ObjectManager
{
	Collision collision;
	InteractionManager intManager;
	//std::vector<std::shared_ptr<GameObject>> objVec;
	std::vector<std::shared_ptr<StaticGameObject>> stObjVec;
	std::vector<std::shared_ptr<DynamicGameObject>> dynObjVec;
public:
	ObjectManager();
	~ObjectManager();
	template<typename... Args>
	std::shared_ptr<DynamicGameObject> createDynamicObject(Args... args) {
		auto obj_ptr = std::make_shared<DynamicGameObject>(args...);
		assert(obj_ptr);
		dynObjVec.push_back(obj_ptr);
		return obj_ptr;
	}
	template<typename... Args>
	std::shared_ptr<StaticGameObject> createStaticObject(Args... args) {
		auto obj_ptr = std::make_shared<StaticGameObject>(args...);
		assert(obj_ptr);
		stObjVec.push_back(obj_ptr);
		return obj_ptr;
	}
	void addDynamicObject(std::shared_ptr<DynamicGameObject> obj_ptr);
	void addStaticObject(std::shared_ptr<StaticGameObject> obj_ptr);
	std::shared_ptr<DynamicGameObject> getDynObject(std::size_t num) const;
	std::shared_ptr<StaticGameObject> getStObject(std::size_t num) const;
	const std::size_t getDynSize() const;
	const std::size_t getStSize() const;
	void render(sf::RenderTarget& target, sf::Time frameTime);
	void update();
	void interact();
};
#endif //OBJECTMANAGER_HPP_