// convoy  �ھ�

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "�����ھ�");
        set("long", @LONG
�����ǵ����ھֵĳ����ֺţ���ʮ����ǰ������ǹ����ݡ�
�����ٳ�����ʦͷ���ڳ������˵����ھ֡�һ����ǹ����ڰ���
�����ڵ����ἰ���������֣���������Ρ�һ������һֻ�޴��
�ͻ���ɽͼ���ſ�������ƿ����������һ�������ܣ���������
�͵Ľ��Ҵ��֡��������á����ɴ����ǳ����ǵı���֡�
LONG
        );
       set("exits", ([
                "north"           : __DIR__"nroad2",
]) );

	set("objects",([
	__DIR__"npc/tangzi_shou" : 2,
]));

        setup();
	replace_program(ROOM);
}
