// Room: /d/huashan/w_daoguan.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��˵����������ڴ��������������ܽ���ڵ���������Ϊ��
�Ժ�����޼��������������ڵ�ʱ�ͺ�����Ӱ�춼�ܴ󡣲�����
�����ҵ�����������µġ��µ��ط���������δ�ɹ���������һ
�����ݵ���̫��ס�Ĵ����ݡ�
LONG
	);

	set("NONPC", 1);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xianguan",
  "west":__DIR__"ciyang",
]));
        set("outdoors", "huashan");
                set("item_desc", (["door": (: look_door, "west" :),
        ]) );

        //set("objects", ([__DIR__"npc/lm_guard": 2 ]) );

        create_door("west","����������","east",DOOR_CLOSED);

        setup();

        setup();
	replace_program(ROOM);
}
