// bank  Ǯׯ

#include <ansi.h>

inherit BANK;

void create()
{
        set("short", "����¡Ǯׯ����ֵ�");
        set("long", @LONG
���ǳ�������¡Ǯׯ�ķ���ֺţ�һ���ţ��Ϳ���ǽ���д�
����(sign)����̨���С���������Ц��ӭ�˹��������������
���Ƿ������Զ·��
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "sign" :  "����¡ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan           ת��
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));

	set("exits", ([
                "north" : __DIR__"wy3",
]) );
        setup();
}
