// Room: kuang.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"��"NOR);
	set("long",@LONG
����һƬ��æ�ľ������¿��Կ���һ������ֱ���ĺ�ɫ��
ʯ����ʮ����ɽ�ɵĵ��������Ӻ�������һ��һ��طֽ�����
ʯ��������ʯͷһ�����Ǽ�Ӳ����Ϊ����ߵĿ���ֻװ��һ��
��ǳǳ�ĵס�
LONG

);
	set("exits", ([ /* sizeof() == 3 */
	
	"down":__DIR__"yunshi",
	"northup":__DIR__"luoyun",
]));

	setup();
	replace_program(ROOM);
}
