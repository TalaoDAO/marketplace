<section class="emh-module person-list-wrapper container">

    <ul class="person-list row">
        <?php $fakeItems = 5; while($fakeItems--): ?>


        <li class="person-wrapper">
            <div class="person <?php print $fakeItems%2?'person-alt':''; ?>">

                <div class="picture">
                    <img src="https://dummyimage.com/100/000/fff.jpg" alt="" />
                </div>

                <div class="content">
                    <div class="name">
                        Prénom nom
                    </div>
                    <div class="position">
                        Lorem ipsum dolor sit amet.
                    </div>
                </div>

            </div>
        </li>


        <?php endwhile; ?>
    </ul>

</section>
