
#include <ansi.h>

inherit NPC;

int ask_me(object me);

void create()
{
        set_name("程贺", ({ "cheng he"}) );
        set("gender", "男性" );
        set("title",HIW"紫月御风行"NOR);
        set("age", 21);
        set("attitude", "peaceful");
        set("per",30);
        set("max_force",3000);
        set("force",3000);
        set("combat_exp",3000000);

        set_skill("sword",250);
        set_skill("force",250);
        set_skill("parry",250);
        set_skill("dodge",250);
        set_skill("literate",100);
        set_skill("unarmed",250);
        set_skill("jieqing-sword",250);
        set_skill("suiyu-force",250);
        set_skill("zuiyue-strike",250);
        set_skill("piaoyu-steps",250);

        map_skill("unarmed","zuiyue-strike");   
        map_skill("dodge","piaoyu-steps");      
        map_skill("parry","jieqing-sword");     
        map_skill("sword","jieqing-sword");     
        map_skill("force","suiyu-force");       

        set("inquiry", ([
                "玉佩" : ("我这里有一面要交给小倩妹妹的玉佩。\n"),
                "唐小倩" : (: ask_me :),
        ]) );
        set("long","程贺有两道浓浓的眉毛和一头飘逸的长发。\n");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        command ("sigh");
        command ("say 小倩妹妹对我实在是太好了，但是感情的事不能勉强。
所以，我也没有办法。我也不想看着他那么难受，所以我一直隐居在这里。\n");
        return 1;
}


int accept_object(object me, object ob)
{
        object obj;

        if(ob->query("id") == "yu pei")
        {
                if (!me->query_temp("louth_shengji1_pei1"))
                {
                        command ("?");
                        command ("say 这枚玉佩是从哪来的？\n");
                        return 1;
                }
        me->delete_temp("louth_shengji1_pei1");
        me->set_temp("louth_shengji1_pei2",1);
        command ("sigh");
        command ("say 想不到这么长时间没有见到小倩妹妹，她还是一直惦记着玉佩的事。\n");
        command ("say 你也帮我把这面玉佩交给小倩妹妹吧，告诉他不要惦记着我，我现在很好。\n");
        return 1;
        }
        return 0;
}
