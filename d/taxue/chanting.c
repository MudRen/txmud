// chanting.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
������̤ѩɽׯ�Ĳ���������̤ѩɽׯ�����˽�����ʳ�����Ե��ӵ�
��ʳҲ����һ���ֳ�ʦ�����ղ�������ֻҪ��һ��(chifan)Ӷ�˾ͻ���
�Ͽɿڵķ��ˡ�
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
        
        message_vision("$N�����Ķ��ӣ����˸����á�\n",ob);
	}
        else write("���Ѿ��Եù������ˣ��㲻�³�����?\n");
        return 1;
}
