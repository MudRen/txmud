// Room: /d/path5/na12.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "�����ϰ�");
	set("long", @LONG
����λ�ڳ����������ϣ������䲻���ؿ���ˮ����Ȼʮ��
�ļ�������ƽʱ����������������Ļ�ֻ��ȥ�ʹ���Ϊ��������
�����������ˡ��ɴ����Ͼ��Ǻ��о����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"na11",
  "east"  : __DIR__"na13",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(8);
	set_yell_msg("$N����ɤ�Ӻ����������ң�����Ҫ������������\n");

        set("outdoors", "path5");
        set("cannot_build_home", 1);
	setup();
}
