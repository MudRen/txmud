
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
���Ǹ��ƾɴ�Ժ,��˵��ǰ�Ǹ����˼ҵ�լ��,���Ǻ�������
ͻȻ�����ʧ��,��Ҳû�г��ֹ�,���˶�ɢ����,�����ط��Ӿ��ƾ���,
��˵������ʧ�����и������ƾɵ���ؤ�����������ֹ�,���˻�����
һ��Թ���,��Ҳ�Ǵ��Ű���.
LONG
        );

	set("exits", ([
               "west"            : __DIR__"road2",
               "east"             : __DIR__"road1",
]) );


	set("objects",([
//:    NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

        create_door("east", "����", "west", DOOR_CLOSED);

         setup();
}
