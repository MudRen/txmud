//����˵�ߵ�ż��
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("����",({"semi","mylove"}));
       set("title",HIR"��ɫ��ʹ"NOR);
        set("age",19);
        set("gender", "Ů��");
        set(NO_KILL,1);

        set("long",@long
    ��˵����о�����ʹ��Ȼ��˭Ҳ��֪����ʮ����ʹ�Ĵ��ڡ�
�����Ƕ���ʹ������ʹ��������ν��������ʹ����û����һ����
�أ�Ҳû����һ����������ֻ�����ڴ���İ����У�Ϊ��������
���������á�����˵��ĳ�쿴�������ı�Ӱ������͵͵�����Լ�
�Ļ�������������������Ӱ�ӡ�
long
       );
        set("str", 20); 
        set("int", 30); 
        set("con", 30);
        set("dex", 30);
        set("per", 100);
        add_temp("apply/unarmed", 900);
        add_temp("apply/armor", 900);
        add_temp("apply/damage", 900);
        add_temp("apply/parry", 900);
        add_temp("apply/dodge", 900);
       
        set("kee",10000);
        set("max_kee",10000);
        set("gin",10000);
        set("max_gin",10000);
        set("sen",10000);
        set("max_sen",10000);
        set("combat_exp",100000000);

         set("inquiry" ,([
        "����":"���ã��а��ĵط���������......",
        "����":"Ϊ�˰��飬��Ը���۶��Լ��ĳ��",
        "��ʹ":"��һ�ִ����������ǰ����ǽ�����ʹ��",
        "����˵��":"����˵����˭���Ҳ���ʶ.....",
        "����":"ʲô���������Ǹ��쵰saying�Ĺ����𣿸�����������ɣ�",
        "all":"����������йء������������飬����Щ���������⣬�Ϳ����Լ���������",
          ]));
           setup();
        carry_object("/d/feiyu/npc/obj/nishang.c")->wear();
        carry_object("/d/feiyu/obj/hflower.c")->wear();

}
