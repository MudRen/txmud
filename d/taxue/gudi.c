// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ�ȵ�");
        set("long",@LONG
�������ͱ�����Ĺȵף���������ϡ�٣�������һƬ�ܺ�Ĳݵأ���
������������ġ����ܿ���ȥ�߲����ʣ���ʯ��ᾣ������в���һ����Ҫ
������Ƭ���Ĳݶѵ��ţ��ٺõ��ṦҲ��ˤ�ñ��һ�����ࡣ��������
�������龰����Ҳ������������˼��������
LONG);

	set("outdoors","taxue");

	set("exits",([
                "west" : __DIR__"gudi1",
                "east" : __DIR__"gudi2",
	]));

	setup();
	replace_program(ROOM);
}