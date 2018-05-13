// zhuoma.c

#include <ansi.h>;

inherit KNOWER;

void create()
{
        set_name("׿��", ({ "zhuo ma", "zhuo", "ma" }));
        set("nickname", HIC "��Ϣ��ͨ" NOR);
        set("long", "����һλ����Ůͬ����\n");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if (! ob) return;

        say (CYN "׿���ʲΪ��˵��������٢��" +
             RANK_D->query_respect(ob) + CYN "��ƶ�����������ˡ�\n" NOR);
}