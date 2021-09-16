// chanting.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","餐厅");
        set("long",@LONG
这里是踏雪山庄的餐厅，由于踏雪山庄的主人讲究饮食，所以弟子的
伙食也不错，一个胖厨师正在烧菜做饭，只要叫一声(chifan)佣人就会送
上可口的饭菜。
LONG);

	set("no_fight",1);
	set("exits",([
		"east" : __DIR__"xilang1",
	]));
	setup();
}
void init()
{
	add_action("do_chifan","chifan");
}

int do_chifan()
{
	object ob=this_player();
	int shiwu,yinshui,current_water,current_food;
	current_water = ob->query("water");
	current_food = ob->query("food");
	shiwu = ob->max_food_capacity();
        yinshui = ob->max_water_capacity();
	
	if (current_water<yinshui || current_food<shiwu) {        
        ob->set("food", shiwu+100);
        ob->set("water", yinshui+100);
        
        message_vision("$N拍了拍肚子，打了个饱嗝。\n",ob);
	}
        else write("你已经吃得够饱的了，你不怕撑着吗?\n");
        return 1;
}
