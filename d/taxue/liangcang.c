// liangcang.c ����
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
�������̤ѩɽׯ�����֣�����������װ�Ÿ��ָ�����ʳ���Ȼ��
�ܺ����֡��䵱��Щ���ǵĴ������ȣ������Ը����㻹��û����ġ���
�ڹ��������̤ѩɽׯ�Ĵ�䣬�����½���һ������õĸ��������ʲô
�ġ���������ҿ���
LONG);

	set("exits",([
		"north" : __DIR__"shilu3",
	]));

	set("objects",([
            
	]));

	setup();
	replace_program(ROOM);
}
