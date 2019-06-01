#include "GameMenu.h"
#include "HitBrick.h"

Scene* GameMenu::createScene()
{
	auto scene = Scene::create();

	auto layer = GameMenu::create();

	scene->addChild(layer);			
	
	return scene;
}

bool GameMenu::init()
{
	if (!Layer::init())

	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();	//获得屏幕大小

	auto label = Label::createWithSystemFont("Play", "fonts/arial.ttf", 30);
	auto menuitem = MenuItemLabel::create(label, CC_CALLBACK_1(GameMenu::EnterHitBrick, this));
	auto menu = Menu::create(menuitem, NULL);
	this->addChild(menu);

	return true;

}

void GameMenu::EnterHitBrick(Ref *pSender)
{
	Director::getInstance()->pushScene(HitBrick::createScene());
}
