/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//	problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//	// position the sprite on the center of the screen
	//	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//	// add the sprite as a child to this layer
	//	this->addChild(sprite, 0);
	//}

	//乱数の初期化
	//Random r = new Random();
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		float mx, my;

		mx = (float)rand() / RAND_MAX * 500;
		my = (float)rand() / RAND_MAX * 500;

		spr[i] = Sprite::create("HelloWorld.png");
		this->addChild(spr[i]);
		spr[i]->setPosition(Vec2(mx,my));
		spr[i]->setScale(0.5f);
		spr[i]->setOpacity(255);
		spr[i]->setAnchorPoint(Vec2(0, 1));

		MoveBy* action1 = MoveBy::create(2.0f, Vec2(mx,my));
		
		spr[i]->runAction(action1);

		FadeOut* action2 = FadeOut::create(5.0f);

		spr[i]->runAction(action2);

		RotateBy* rote = RotateBy::create(5.0f, 300);

		spr[i]->runAction(rote);
	}

#pragma region MyRegion



		//// テクスチャファイル名を指定して、スプライトを作成
		//	sprite = Sprite::create("sample09.png");
		//	sprite2 = Sprite::create("sample08.png");
		//
		//	// シーングラフにつなぐ
		//	this->addChild(sprite);
		//	sprite->setPosition(Vec2(visibleSize.width / 2.0f - 50, visibleSize.height / 2.0f));
		//	this->addChild(sprite2);
		//	sprite2->setPosition(Vec2(visibleSize.width / 2.0f + 50, visibleSize.height / 2.0f));
		//	//sprite->setRotation(45.0f);
		//	sprite->setScale(4.0f, 4.0f);
		//	sprite2->setScale(4.0f, 4.0f);
		//	//sprite->setFlippedX(true);
		//	//sprite->setFlippedY(true);
		//	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
		//	sprite->setOpacity(255);
		//	sprite2->setOpacity(0);
		//	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
		//	//sprite->setFlippedX(true);//反転
		//	sprite->setTextureRect(Rect(0, 0, 32, 32));
		//	sprite2->setTextureRect(Rect(0, 0, 32, 32));
		//
		//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(200, 100));
		//	//ScaleTo* action2 = ScaleTo::create(1.0f, 5.0f);
		//	//JumpTo* action3 = JumpTo::create(1.0f,Vec2(200,100),500,2);
		//
		//	//ccBezierConfig conf;
		//	//conf.controlPoint_1 = Vec2(500, 500);
		//	//conf.controlPoint_2 = Vec2(500, 100);
		//	//conf.endPosition = Vec2(200, 100);
		//	//BezierTo* action4 = BezierTo::create(1.0f, conf);
		//
		//	EaseBounceIn* action2 = EaseBounceIn::create(action1);
		//
		//	sprite->runAction(action2);
		//
		//	this->scheduleUpdate();
		//
		//	//move[0] = Vec2(1200, 500);
		//	//move[1] = Vec2(100, 500);
		//	//move[2] = Vec2(100, 100);
		//	//move[3] = Vec2(1200, 100);
		//
		//	move2[0] = Vec2(0, visibleSize.height / 2.0f);
		//	move2[1] = Vec2(visibleSize.width, visibleSize.height / 2.0f);
		//
		//	counter = 0;
		//	bal = true;
		//	bal2 = false;
		//
		//	cunt = 0;

#pragma endregion

		return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delte)
{

#pragma region MyRegion

	////	更新処理

	////Vec2 pos = sprite->getPosition();

	////if ((move[p] - pos).getLength() < 1)
	////{
	////	p += 1;
	////	if (p == 4) 
	////	{
	////		p = 0;
	////	}
	////}
	////Vec2 velocity = move[p] - pos;
	////velocity.normalize();
	////pos = pos + velocity *2;
	////sprite->setPosition(pos);

	////回転

	////アニメ

	//cunt += 1;
	//
	//if (cunt <= 1)
	//{
	//	sprite->setTextureRect(Rect(0, 32, 32, 32));
	//}
	//else if (cunt / 60 > 1 && cunt / 60 <= 2)
	//{
	//	sprite->setTextureRect(Rect(32, 32, 32, 32));
	//}
	//else if(cunt / 60 > 2 && cunt / 60 <= 3)
	//{
	//	sprite->setTextureRect(Rect(64, 32, 32, 32));
	//	
	//}
	//else if(cunt / 60 > 3 && cunt / 60 <= 4)
	//{
	//	sprite->setTextureRect(Rect(32, 32, 32, 32));
	//}
	//else if (cunt / 60 > 4 )
	//{
	//	cunt = 0;
	//}

	////float cntval = 60 * 2;
	////float o = 0;

	////if (bal)
	////{
	////	counter++;
	////	o = 255 - (counter / cntval * 255.0f);
	////	if (o < 0)
	////	{
	////		counter = 0;
	////		o = 0;
	////		bal = false;
	////	}
	////}
	////else if (!bal)
	////{
	////	counter++;
	////	o = counter / cntval * 255.0f;
	////	if (o > 255)
	////	{
	////		counter = 0;
	////		o = 255;
	////		bal = true;
	////	}
	////}
	////opa = o;
	////sprite->setOpacity(opa);

	//float cntval2 = 60 * 2;
	//float o2 = 255;

	//if (bal2)
	//{
	//	counter2++;
	//	o2 = 255 - (counter2 / cntval2 * 255.0f);
	//	if (o2 < 0)
	//	{
	//		counter2 = 0;
	//		o2 = 0;
	//		bal2 = false;
	//	}
	//}
	//else if (!bal2)
	//{
	//	counter2++;
	//	o2 = counter2 / cntval2 * 255.0f;
	//	if (o2 > 255)
	//	{
	//		counter2 = 0;
	//		o2 = 255;
	//		bal2 = true;
	//	}
	//}
	//opa2 = o2;
	//sprite2->setOpacity(opa2);



	//Vec2 pos2 = sprite->getPosition();

	//if ((move2[p2] - pos2).getLength() < 1)
	//{
	//	p2 += 1;
	//	sprite->setFlippedX(true);//反転
	//	sprite2->setFlippedX(true);//反転
	//	if (p2 == 2)
	//	{
	//		sprite->setFlippedX(false);//反転
	//		sprite2->setFlippedX(false);//反転
	//		p2 = 0;
	//	}
	//}

	//Vec2 velocity = move2[p2] - pos2;
	//velocity.normalize();
	//pos2 = pos2 + velocity * 2;
	//sprite->setPosition(pos2);
	//sprite2->setPosition(pos2+(Vec2(100,0)));
#pragma endregion

}