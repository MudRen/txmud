// chitang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","����");
	set("long", @LONG
һ�س�ˮӳ�����������С������Ȼˮ�У����۵�ʯ���ϼ������ٻ��
С�ص����ߣ��������������գ�������С��ʯ��֮�ϣ�������㣬������Ƣ��
���£�ˮ��������ʯ���أ��㲻��Ϊ�˾�����̾���ѡ�
LONG	);
        set("exits", ([ 
	"west" : __DIR__"houyuan",
	"north" : __DIR__"undertree",
	]));

	set("outdoors", "taxue" );
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}